<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {font-family: Arial, Helvetica, sans-serif;}
form {border: 3px solid #f1f1f1;}

input[type=text], input[type=password] {
  width: 30%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  box-sizing: border-box;
}

button {
  background-color: #4CAF50;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  cursor: pointer;
  width: 25%;
}

button:hover {
  opacity: 0.8;
}

.container {
  padding: 16px;
}

</style>
</head>
<body>

<h2>Login Form</h2>

<form action="succ_login_sh.php">

  <div class="container">
    <label for="PanNumber"><b>Pan Number</b></label>
    <br>
    <input type="text" placeholder="Enter Pan Number" name="PanNumber" required>
    <br>
    <br>

    <label for="phoneno"><b>Phone No</b></label>
    <br>
    <input type="password" placeholder="Enter Phone No" name="phoneno" required>
    <br>
    <br>
        
    <button type="submit">Login</button>
  </div>
  
</form>

</body>
</html>