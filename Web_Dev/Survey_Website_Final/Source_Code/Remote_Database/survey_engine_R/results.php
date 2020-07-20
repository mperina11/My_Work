<?php

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

        //survey1
        $r1_1 =0;
        $r1_2 =0;
        $r1_3 =0;
        $r1_4 =0;
        $r1_5 =0;
        $r1_6 =0;
        $r1_7 =0;
        $r1_8 =0;
        $hold1= (isset($_POST['check1']) ? $_POST['check1'] : null);
        if(empty($hold1)){
            //nothing
        } else {
        $N1 = count($hold1);
        
        for($i=0; $i < $N1; $i++)
        {
          $temp1 = $hold1[$i];
          if($temp1 == "A"){
              $r1_1 = 1;
              }
          if($temp1 == "B"){
              $r1_2 = 1;
              }
          if($tem1 == "C"){
              $r1_3 = 1;
              }
          if($temp1 == "D"){
              $r1_4 = 1;
              }
          if($temp1 == "E"){
              $r1_5 = 1;
              }
          if($temp1 == "F"){
              $r1_6 = 1;
              }
          if($temp1 == "G"){
              $r1_7 = 1;
              }
          if($temp1 == "H"){
              $r1_8 = 1;
              }
              
        } //for
        
        $sql_d1 = "DROP TABLE IF EXISTS `mperina_result_1_2`;";
        if ($conn->query($sql_d1) === TRUE) {
          echo "Table dropped successfully";
        } else {
          echo "Left alone" . $conn->error;
        }
        // sql to create table
        $sql = "CREATE TABLE mperina_result_1_2 (
          `id_result_1` int(10) NOT NULL AUTO_INCREMENT,
          `r1` int(10) DEFAULT NULL,
          `r2` int(10) DEFAULT NULL,
          `r3` int(10) DEFAULT NULL,
          `r4` int(10) DEFAULT NULL,
          `r5` int(10) DEFAULT NULL,
          `r6` int(10) DEFAULT NULL,
          `r7` int(10) DEFAULT NULL,
          `r8` int(10) DEFAULT NULL,
          PRIMARY KEY (`id_result_1`)
        )";

        if ($conn->query($sql) === TRUE) {
          echo "Table created successfully";
        } else {
          echo "Error creating table: " . $conn->error;
        }    
        
        //insert 
        $sql_1 = "INSERT INTO mperina_result_1_2 (r1, r2, r3, r4, r5, r6, r7, r8)
        VALUES ('$r1_1', '$r1_2','$r1_3','$r1_4','$r1_5','$r1_6','$r1_7','$r1_8')";
        }
        
        //survey2
        $r2_1 =0;
        $r2_2 =0;
        $r2_3 =0;
        $r2_4 =0;
        $r2_5 =0;
        $r2_6 =0;
        $r2_7 =0;
        $r2_8 =0;
        $hold2= (isset($_POST['check2']) ? $_POST['check2'] : null);
         if(empty($hold2)){
            //nothing
        } else {
        $N2 = count($hold2);
        
        for($i=0; $i < $N2; $i++)
        {
          $temp2 = $hold2[$i];
          if($temp2 == "A"){
              $r2_1 = 1;
              }
          if($temp2 == "B"){
              $r2_2 = 1;
              }
          if($temp2 == "C"){
              $r2_3 = 1;
              }
          if($temp2 == "D"){
              $r2_4 = 1;
              }
          if($temp2 == "E"){
              $r2_5 = 1;
              }
          if($temp2 == "F"){
              $r2_6 = 1;
              }
          if($temp2 == "G"){
              $r2_7 = 1;
              }
          if($temp2 == "H"){
              $r2_8 = 1;
              }
              
        } //for
        
        $sql_d2 = "DROP TABLE IF EXISTS `mperina_result_2_2`;";
        if ($conn->query($sql_d2) === TRUE) {
          echo "Table dropped successfully";
        } else {
          echo "Left alone" . $conn->error;
        }
        // sql to create table
        $sql2 = "CREATE TABLE mperina_result_2_2 (
          `id_result_2` int(10) NOT NULL AUTO_INCREMENT,
          `r1` int(10) DEFAULT NULL,
          `r2` int(10) DEFAULT NULL,
          `r3` int(10) DEFAULT NULL,
          `r4` int(10) DEFAULT NULL,
          `r5` int(10) DEFAULT NULL,
          `r6` int(10) DEFAULT NULL,
          `r7` int(10) DEFAULT NULL,
          `r8` int(10) DEFAULT NULL,
          PRIMARY KEY (`id_result_2`)
        )";

        if ($conn->query($sql2) === TRUE) {
          echo "Table created successfully";
        } else {
          echo "Error creating table: " . $conn->error;
        }    
        
        //insert 
        $sql_2 = "INSERT INTO mperina_result_2_2 (r1, r2, r3, r4, r5, r6, r7, r8)
        VALUES ('$r2_1', '$r2_2','$r2_3','$r2_4','$r2_5','$r2_6','$r2_7','$r2_8')";
        }
        
        //survey1
        $r3_1 =0;
        $r3_2 =0;
        $r3_3 =0;
        $r3_4 =0;
        $r3_5 =0;
        $r3_6 =0;
        $r3_7 =0;
        $r3_8 =0;
        $hold3= (isset($_POST['check3']) ? $_POST['check3'] : null);
         if(empty($hold3)){
            //nothing
        } else {
        $N3 = count($hold3);
        
        for($i=0; $i < $N3; $i++)
        {
          $temp3 = $hold3[$i];
          if($temp3 == "A"){
              $r3_1 = 1;
              }
          if($temp3 == "B"){
              $r3_2 = 1;
              }
          if($temp3 == "C"){
              $r3_3 = 1;
              }
          if($temp3 == "D"){
              $r3_4 = 1;
              }
          if($temp3 == "E"){
              $r3_5 = 1;
              }
          if($temp3 == "F"){
              $r3_6 = 1;
              }
          if($temp3 == "G"){
              $r3_7 = 1;
              }
          if($temp3 == "H"){
              $r3_8 = 1;
              }
              
        } //for
        
        $sql_d3 = "DROP TABLE IF EXISTS `mperina_result_3_2`;";
        if ($conn->query($sql_d3) === TRUE) {
          echo "Table dropped successfully";
        } else {
          echo "Left alone" . $conn->error;
        }
        // sql to create table
        $sql2 = "CREATE TABLE mperina_result_3_2 (
          `id_result_3` int(10) NOT NULL AUTO_INCREMENT,
          `r1` int(10) DEFAULT NULL,
          `r2` int(10) DEFAULT NULL,
          `r3` int(10) DEFAULT NULL,
          `r4` int(10) DEFAULT NULL,
          `r5` int(10) DEFAULT NULL,
          `r6` int(10) DEFAULT NULL,
          `r7` int(10) DEFAULT NULL,
          `r8` int(10) DEFAULT NULL,
          PRIMARY KEY (`id_result_3`)
        )";

        if ($conn->query($sql2) === TRUE) {
          echo "Table created successfully";
        } else {
          echo "Error creating table: " . $conn->error;
        }    
        
        //insert 
        $sql_3 = "INSERT INTO mperina_result_3_2 (r1, r2, r3, r4, r5, r6, r7, r8)
        VALUES ('$r3_1', '$r3_2','$r3_3','$r3_4','$r3_5','$r3_6','$r3_7','$r3_8')";
        }
        
        
        //successful?
        if ($conn->query($sql_1) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql_1 . "<br>" . $conn->error;
        }
                //successful?
        if ($conn->query($sql_2) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql_2 . "<br>" . $conn->error;
        }
                //successful?
        if ($conn->query($sql_3) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql_3 . "<br>" . $conn->error;
        }
         $conn->close();

header("Location:index.html");

?>