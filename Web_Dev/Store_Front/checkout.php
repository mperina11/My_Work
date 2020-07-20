<!DOCTYPE html>
<html>
<body>

        <?php 
              
        $Temp_f_name= (isset($_POST['firstname']) ? $_POST['firstname'] : null);
        $f_name= filter_var($Temp_f_name, FILTER_SANITIZE_STRING);
        $Temp_email= (isset($_POST['email']) ? $_POST['email'] : null);
        $email= filter_var($Temp_email, FILTER_SANITIZE_EMAIL);
        $Temp_address= (isset($_POST['address']) ? $_POST['address'] : null);
        $address= filter_var($Temp_address, FILTER_SANITIZE_STRING);
        $Temp_city= (isset($_POST['city']) ? $_POST['city'] : null);
        $city= filter_var($Temp_city, FILTER_SANITIZE_STRING);
        $Temp_state= (isset($_POST['state']) ? $_POST['state'] : null);
        $state= filter_var($Temp_state, FILTER_SANITIZE_STRING);
        $Temp_zip= (isset($_POST['zip']) ? $_POST['zip'] : null);
        $zip= filter_var($Temp_zip, FILTER_SANITIZE_NUMBER_INT);
        

        $Temp_cardname= (isset($_POST['cardname']) ? $_POST['cardname'] : null);
        $cardname= filter_var($Temp_cardname, FILTER_SANITIZE_STRING);
        $Temp_cardnumber= (isset($_POST['cardnumber']) ? $_POST['cardnumber'] : null);
        $cardnumber= filter_var($Temp_cardnumber, FILTER_SANITIZE_NUMBER_INT);
        $Temp_expmonth= (isset($_POST['expmonth']) ? $_POST['expmonth'] : null);
        $expmonth= filter_var($Temp_expmonth, FILTER_SANITIZE_STRING);
        $Temp_expyear= (isset($_POST['expyear']) ? $_POST['expyear'] : null);
        $expyear= filter_var($Temp_expyear, FILTER_SANITIZE_NUMBER_INT);
        $Temp_cvv= (isset($_POST['cvv']) ? $_POST['cvv'] : null);
        $cvv= filter_var($Temp_cvv, FILTER_SANITIZE_NUMBER_INT);
        

        echo $f_name;
        echo $email;
        echo $address;
        echo $city;
        echo $state;
        echo $zip;
        
        echo $cardname;
        echo $cardnumber;
        echo $expmonth;
        echo $expyear;
        echo $cvv;
        
        
        //database var
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
        
        //insert to checkout 
        $sql = "INSERT INTO checkout (full_name, email, address, city, state, zip, cardname, cardnumber, expmonth, expyear, cvv)
        VALUES ('$f_name', '$email', '$address','$city','$state','$zip','$cardname','$cardnumber','$expmonth','$expyear','$cvv')";

        
        //insert to cart 
        $i9 =0;
        $i7 =0;
        $i5 =0;
        $i3 =0;
        $r9 =0;
        $r7 =0;
        $r5 =0;
        $r3 =0;
        //$hold = $_POST['check'];
        $hold= (isset($_POST['check']) ? $_POST['check'] : null);

        $N = count($hold);        
        for($i=0; $i < $N; $i++)
        {
          $temp = $hold[$i];
          if($temp == "A"){
              $i9 = 1;
              }
          if($temp == "B"){
              $i7 = 2;
              }
          if($temp == "C"){
              $i5 = 3;
              }
          if($temp == "D"){
              $i3 = 4;
              }
          if($temp == "E"){
              $r9 = 5;
              }
          if($temp == "F"){
              $r7 = 6;
              }
          if($temp == "G"){
              $r5 = 7;
              }
          if($temp == "H"){
              $r3 = 8;
              }
              
        } //for
        
        $sql_c = "INSERT INTO cart (i9, i7, i5, i3, r9, r7, r5, r3)
        VALUES ('$i9', '$i7','$i5','$i3','$r9','$r7','$r5','$r3')";
        
        
        
        
        
        //successful?
        if ($conn->query($sql) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql . "<br>" . $conn->error;
        }
        
                //successful?
        if ($conn->query($sql_c) === TRUE) {
          echo "New record created successfully";
        } else {
          echo "Error: " . $sql_c . "<br>" . $conn->error;
        }
        
        
        $conn->close();
        
        header("Location:index.html");
        
        ?>
</body>
</html> 