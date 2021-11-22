<html>
  <font color="red"><h1><marquee> Secure Login Page </marquee></h1></font>
  <hr>
  <body style="background-color:powderblue;">
      <center><form method="POST" name="<?php basename($_SERVER['PHP_SELF']); ?>">

        Usuario: <input type="text" name="usuario" id="usuario" size="30">
        
        &nbsp; <! da espaxio entre Usuario y Passwrod en el navegador >

        Password: <input type="password" name="password" id="password">

        <input type="submit" value="Login">

    </form></center>

  <?php
    echo "Hola";
    echo basename($_SERVER['PHP_SELF']);
    
    $USER = "admin";
    $PASSWORD = "4STDSFPASSWORDULTRASEGUROQUENIDELOCOCONSEGUIREPORFUERZABRUTADICCIONARIO..";

    if( isset($_POST['usuario']) && isset($_POST['password'] )){
      if( $_POST['usuario'] == $USER ){
        if( strcmp($_POST['password'], $PASSWORD) == 0 ){
          echo " Acceso Garantizado... El PIN es 4671";
        }
        else{
          echo " La password es incorrecta! :( ";
        }
      }
      else{
        echo " El usuario es invalido... :( ";
      }
    }

  ?>

  </body>
</html>
