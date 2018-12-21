const char landingPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Moto</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        html    {
            height: 100%;
        }

        body    {
            background: #2c3e50;
            height: 100%;
        }

        .stl    {
            color: antiquewhite;
            font-size: 50px;
            border: 5px wheat solid;
            border-radius: 10%;
            margin: 100px;
            transform: rotate(90deg);
        }

        #down   {
            padding: 100px;
            position: absolute;
        }
        #up    {
            float: right;
            padding: 100px 150px;
        }

        #left  {
            position: fixed;
            bottom: 400px;
            padding: 100px;
        }

        #right  {
            position: fixed;
            bottom: 10px;
            padding: 100px;
        }
        </style>
</head>
<body>
    
    <div>
        <span id="down" class="stl">DOWN</span>
        <span id="up" class="stl">UP</span>
    </div>
    <div>
        <span id="left" class="stl">LEFT</span>
        <span id="right" class="stl">RIGHT</span>
    </div>

    <script>

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
    var up = document.querySelector("#up");
    var down = document.querySelector("#down");
    var left = document.querySelector("#left");
    var right = document.querySelector("#right");

    up.addEventListener("touchstart", ()=>{
        movement("up");
    });
    up.addEventListener("touchend", ()=>{
        movement("stop");
    });
    down.addEventListener("touchstart", ()=>{
        movement("down");
    });
    down.addEventListener("touchend", ()=>{
        movement("stop");
    });
    left.addEventListener("touchstart", ()=>{
        movement("left");
    });
    left.addEventListener("touchend", ()=>{
        movement("stop");
    });
    right.addEventListener("touchstart", ()=>{
        movement("right");
    });
    right.addEventListener("touchend", ()=>{
        movement("stop");
    });

    </script>
</body>
</html>

    )=====";