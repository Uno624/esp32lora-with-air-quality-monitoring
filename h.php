<?php
class AirflowDataHandler {
    private $link;

    public function __construct($packet, $pm1, $pm2_5, $pm10, $Temperature, $ApproxAltitude, $Pressure, $Latitude, $Longitude, $Altitude_in_feet, $Speed_in_knots) {
        $this->connect();
        $this->storeInDB($packet, $pm1, $pm2_5, $pm10, $Temperature, $ApproxAltitude, $Pressure, $Latitude, $Longitude, $Altitude_in_feet, $Speed_in_knots);
        $this->closeConnection();
    }

    private function connect() {
        $host = 'XXXX';
        $username = 'XXXX';
        $password = 'XXXXX';
        $database = 'XXXXX';

        $this->link = mysqli_connect($host, $username, $password, $database) or die('ไม่สามารถเชื่อมต่อกับฐานข้อมูลได้');
        mysqli_query($this->link, "SET NAMES 'utf8'");
        date_default_timezone_set('Asia/Bangkok');
    }

    private function storeInDB($packet, $pm1, $pm2_5, $pm10, $Temperature, $ApproxAltitude, $Pressure, $Latitude, $Longitude, $Altitude_in_feet, $Speed_in_knots) {
        // ใช้ prepared statement
        $query = "INSERT INTO h SET Dtime=?, packet=?, pm1=?, pm2_5=?, pm10=?, Temperature=?, ApproxAltitude=?, Pressure=?, Latitude=?, Longitude=?, Altitude_in_feet=?, Speed_in_knots=?";
        $stmt = mysqli_prepare($this->link, $query);

        // Bind parameters
        $dtime = date('Y-m-d H:i:s');
        mysqli_stmt_bind_param($stmt, 'ssssssssssss', $dtime, $packet, $pm1, $pm2_5, $pm10, $Temperature, $ApproxAltitude, $Pressure, $Latitude, $Longitude, $Altitude_in_feet, $Speed_in_knots);

        // Execute the query
        mysqli_stmt_execute($stmt);

        // ปิด statement
        mysqli_stmt_close($stmt);
    }

    private function closeConnection() {
        mysqli_close($this->link);
    }
}

if (
    isset($_GET['p']) && $_GET['p'] != '' &&
    isset($_GET['p1']) && $_GET['p1'] != '' &&
    isset($_GET['p5']) && $_GET['p5'] != '' &&
    isset($_GET['p10']) && $_GET['p10'] != '' &&
    isset($_GET['T']) && $_GET['T'] != '' &&
    isset($_GET['AA']) && $_GET['AA'] != '' &&
    isset($_GET['P']) && $_GET['P'] != '' &&
    isset($_GET['La']) && $_GET['La'] != '' &&
    isset($_GET['Lo']) && $_GET['Lo'] != '' &&
    isset($_GET['AF']) && $_GET['AF'] != '' &&
    isset($_GET['Sk']) && $_GET['Sk'] != ''
) {
    $airflowDataHandler = new AirflowDataHandler(
        $_GET['p'], $_GET['p1'], $_GET['p5'], $_GET['p10'], $_GET['T'], $_GET['AA'], $_GET['P'], $_GET['La'], $_GET['Lo'], $_GET['AF'], $_GET['Sk']
    );
}
?>