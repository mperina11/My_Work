<!DOCTYPE html>
<html>
<body>

        <?php 
        session_start();
        
        $Temp_uname = (isset($_POST['uname']) ? $_POST['uname'] : null);
        $uname = filter_var($Temp_uname, FILTER_SANITIZE_STRING);
        $Temp_psw = (isset($_POST['psw']) ? $_POST['psw'] : null);
        $psw = filter_var($Temp_psw, FILTER_SANITIZE_STRING);        
        
        //hash the password
        $hash_psw = sha1($psw);        
       
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
        
        //select, get username and password to verify
        $sql_select="SELECT `uname`, `psw` FROM `mperina_login_2`;";
        $result=$conn->query($sql_select);
        
        $authorization = false;
        while($re = $result->fetch_assoc()){
                  $uname_select = $re['uname'];
                  $psw_select = $re['psw'];
                  
                  if($uname == $uname_select && $hash_psw == $psw_select){
                      $authorization = true;
                  }
        } 
        
        if ($authorization == true) {
            
            
        $sql_d1 = "DROP TABLE IF EXISTS `mperina_session_2`;";
        if ($conn->query($sql_d1) === TRUE) {
          echo "Table dropped successfully";
        } else {
          echo "Left alone" . $conn->error;
        }
        // sql to create table
        $sql = "CREATE TABLE mperina_session_2 (
          `id_session_key` int(10) NOT NULL AUTO_INCREMENT,
          `username` varchar(50) DEFAULT NULL,
          `time_log_in` varchar(50) DEFAULT NULL,
          `time_log_out` varchar(50) DEFAULT NULL,
          PRIMARY KEY (`id_session_key`)
        )";

        if ($conn->query($sql) === TRUE) {
          echo "Table created successfully";
        } else {
          echo "Error creating table: " . $conn->error;
        }    
            
        //save time of login
        $time_in = date("H:i:s");
        $sql = "INSERT INTO mperina_session_2 (username, time_log_in)
        VALUES ('$uname', '$time_in')";
        
        //select larget id to set user cookie and session var   
        //having issues using 'Max()' had to do it manually
        $sql_id="SELECT id_session_key FROM mperina_session_2";
        $results_id=$conn->query($sql_id);
        while($row = $results_id->fetch_assoc()) {
             $id = $row["id_session_key"];
        }
        echo $id;
                
        //set cookie and session
        //setcookie($id,id);
        $_SESSION["id"] = $id + 1;

        if ($conn->query($sql) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql . "<br>" . $conn->error;
        }
            
        $conn->close();
        header("Location:index.html");    
        
        } else {            
            header("Location:loginpage.html"); //display wrong u $ p , or make second page with error message           
        }
        
        ?>
</body>
</html> 