<?php
    session_start();

    //get cookie and session
    ////cookie having issues
    //echo "Value is: " . $_COOKIE['id'];
    echo "Value is: " . $_SESSION["id"];
    
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "cpu_store";
    
    $time_out = date("H:i:s");
    $id = $_SESSION["id"];

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
    } 

//    $sql_select="SELECT `id_session_key`, `session_id` FROM `session`;";
//        $result=$conn->query($sql_select);
//        
//        while($re = $result->fetch_assoc()){
//                  $session_id_select = $re['session_id'];
//                  $id_table = $re['id_session_key'];
//                  
//                  if($session_id_select == '$_SESSION[$uname]'){
//                      $id = $id_table;
//                  }
//        } 
//    echo"id of table " . $id;
//    echo"session id " . $session_id_select;
//    echo"session id name " . $_SESSION[$uname];
    //VALUES ('$time_out')";
    $sql = "UPDATE session SET time_log_out='$time_out' WHERE id_session_key='$id'";

    if ($conn->query($sql) === TRUE) {
      echo "New record created successfully";
    } else {
      echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
        
        
    session_unset();
    session_destroy();
    header("Location:loginpage.html");    
?>