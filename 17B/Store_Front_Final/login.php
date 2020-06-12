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
       
        //send to database
        $servername = "localhost";
	$username = "root";
	$password = "";
	$dbname = "cpu_store";

	// Create connection
	$conn = new mysqli($servername, $username, $password, $dbname);
	// Check connection
	if ($conn->connect_error) {
		die("Connection failed: " . $conn->connect_error);
	} 
        
        //select, get username and password to verify
        $sql_select="SELECT `uname`, `psw` FROM `login`;";
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
            
        //save time of login
        $time_in = date("H:i:s");
        $sql = "INSERT INTO session (username, time_log_in)
        VALUES ('$uname', '$time_in')";
        
        //select larget id to set user cookie and session var   
        //having issues using 'Max()' had to do it manually
        $sql_id="SELECT id_session_key FROM session";
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