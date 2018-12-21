const char landingPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Moto</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    
    <h4 id="just">Khali</h4>

    function movement(move) {
        var req_param=String(move);
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                var value = String(this.responseText);
            }
        };
        xhttp.open("GET", req_param, true);
        xhttp.send();
    }


    </script>
</body>
</html>

    )=====";