var socket;

//sending data to bluetooth controller
function openSocket() {
    socket.send("Player connecting...");
}

//showing received data from bluetooth controller
function showData(result) {
    console.log(result.data);
	console.log("We got hit");1
}

$(document).ready(function(){

    socket = new WebSocket("ws://localhost:8081");

    // The socket connection needs two event listeners:
    socket.onopen = openSocket;
    socket.onmessage = showData;
});

function forward(){
    socket.send("w");

}
function shoot() {
	socket.send("r");
}

function backwards(){
    socket.send("s");
}

function right(){
    socket.send("d");
}

function left(){
    socket.send("a");
}

function stop(){
    socket.send("z");
}