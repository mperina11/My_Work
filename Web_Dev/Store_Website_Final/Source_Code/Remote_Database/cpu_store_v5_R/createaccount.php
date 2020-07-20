<!DOCTYPE html>
<html>
<body>

        <?php 

        $Temp_fname = (isset($_POST['firstname']) ? $_POST['firstname'] : null);
        $fname = filter_var($Temp_fname, FILTER_SANITIZE_STRING);  
        $Temp_lname = (isset($_POST['lastname']) ? $_POST['lastname'] : null);
        $lname = filter_var($Temp_lname, FILTER_SANITIZE_STRING);
        $Temp_email = (isset($_POST['email']) ? $_POST['email'] : null);
        $email = filter_var($Temp_email, FILTER_SANITIZE_STRING);  
        $Temp_uname = (isset($_POST['uname']) ? $_POST['uname'] : null);
        $uname = filter_var($Temp_uname, FILTER_SANITIZE_STRING);
        $Temp_psw = (isset($_POST['psw']) ? $_POST['psw'] : null);
        $psw = filter_var($Temp_psw, FILTER_SANITIZE_STRING);        
        
        $hash_psw = sha1($psw);
        
        //REGEX
        $regex_n = "^[a-zA-Z]";
        $regex_u = "^[a-z0-9_-]{3,15}$";
        $regex_p = "((?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[@#$%]).{6,20})";
        $regex_e = "^[_A-Za-z0-9-]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9]+
                    (\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$";
        
        if (preg_match('/'.$regex_n.'/', $fname)) { //first name
            $state_fn = true;
        } else {
            $state_fn = false;
        }
        if (preg_match('/'.$regex_n.'/', $lname)) { //last name
            $state_ln = true;
        } else {
            $state_ln = false;
        }
//        if (preg_match('/'.$regex_e.'/', $email)) { //email
//            $state_e = true;
//        } else {
//            $state_e = false;
//        }        
        if (preg_match('/'.$regex_u.'/', $uname)) { //username
            $state_u = true;
        } else {
            $state_u = false;
        }        
        if (preg_match('/'.$regex_p.'/', $psw)){    //password
            $state_p = true;
        } else {
            $state_p = false;
        }
        //debug
        $state_e = true;
        
        //check if passed REGEX
        if($state_fn==true || $state_ln==true || $state_e==true || $state_u==true || $state_p==true){
        
       //database var
        $servername = "209.129.8.7";
	$username = "RCCCSCCIS17B";
	$password = "4050240368";
	$dbname = "RCCCSCCIS17B";

	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	} 
        
        $sql_d1 = "DROP TABLE IF EXISTS `mperina_login`;";
        if ($conn->query($sql_d1) === TRUE) {
          echo "Table dropped successfully";
        } else {
          echo "Left alone" . $conn->error;
        }
        // sql to create table
        $sql = "CREATE TABLE mperina_login (
          `id_login` int(10) NOT NULL AUTO_INCREMENT,
          `uname` varchar(50) DEFAULT NULL,
          `psw` varchar(50) DEFAULT NULL,
          `first_name` varchar(50) DEFAULT NULL,
          `last_name` varchar(50) DEFAULT NULL,
          `email` varchar(50) DEFAULT NULL,
          PRIMARY KEY (`id_login`)
        )";

        if ($conn->query($sql) === TRUE) {
          echo "Table created successfully";
        } else {
          echo "Error creating table: " . $conn->error;
        }
        
        $sql_d2 = "DROP TABLE IF EXISTS `mperina_user`;";
        if ($conn->query($sql_d2) === TRUE) {
          echo "Table dropped successfully";
        } else {
          echo "Left alone" . $conn->error;
        }
        
                // sql to create table
        $sql_2 = "CREATE TABLE mperina_user (
          `id_user` int(10) NOT NULL AUTO_INCREMENT,
          `fname` varchar(50) DEFAULT NULL,
          `lname` varchar(50) DEFAULT NULL,
          `email` varchar(50) DEFAULT NULL,
          PRIMARY KEY (`id_login`)
        )";

        if ($conn->query($sql_2) === TRUE) {
          echo "Table created successfully";
        } else {
          echo "Error creating table: " . $conn->error;
        }
        
        $sql = "INSERT INTO mperina_login (uname, psw, first_name, last_name, email)
        VALUES ('$uname', '$hash_psw', '$fname', '$lname', '$email')";
        
        $sql_2 = "INSERT INTO mpeirna_user (fname, lname, email)
        VALUES ('$fname', '$lname', '$email')";
        
        
        if ($conn->query($sql) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql . "<br>" . $conn->error;
        }
        
        if ($conn->query($sql_2) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql_2 . "<br>" . $conn->error;
        }
        $conn->close();
        
        header("Location:loginpage.html");
        } 
        else {
            header("Location:loginpage.html");
        }
        
        ?>
</body>
</html> 