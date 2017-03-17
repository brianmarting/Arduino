var socket;
//var request = require('request');

//sending data to bluetooth controller
function openSocket() {
    socket.send("Player connecting...");
}

//showing received data from bluetooth controller
function showData(result) {
    console.log(result.data);
    console.log("We got hit!!");
    getHit();
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

function backwards(){
    socket.send("s");
}

function right(){
    socket.send("d");
}

function left(){
    socket.send("a");
}

function fire(){
    socket.send("r");
}

function stop(){
    socket.send("z");
}

/*var user_details = {
 ammo: {}
 };

 var login_data = {
 'name': 'ROBOB'
 };

 var login_data = "name=ROBOB";

 var queue = false;*/

var game_id = 0;
var player_id = 1;
var ip = '172.31.31.40';
var port = '3000';

function getHit(){
	
	$.ajax({
		type: 'POST',
		url: "http://" + ip + ":" + port + "/game/" + game_id + "/player/" + player_id + "/hit",
		async: true,
		contentType: "application/json",
		dataType: 'json',
		success:
			function(data) {
				console.log('We got hit and damage is done');
			},
		error:
			function(XMLHttpRequest, textStatus, errorThrown) {
				
			
			}
	});
	
    /*request(
        {
            url: "http://" + ip + ":" + port + "/game/" + game_id + "/player/" + player_id + "/hit",
            method: "POST",
            json: true
        },
        function (error, response, body){
            console.log('We got hit and damage is done');
        });*/
}

//only gets, doesnt log you in
/*function getRobot(){
 request(
 {
 url: "http://" + ip + ":" + port + "/game/" + game_id + "/player/" + player_id,
 method: "GET",
 json: true
 },
 function (error, response, body){

 console.log("\nLOGGING IN \n");

 user_details.name = body.name;
 user_details.id = body.id;
 user_details.health = body.health;

 console.log("We're logged in and got our details: \n");

 console.log("ID: " + user_details.id);
 console.log("Name: " + user_details.name);
 console.log("Health: " + user_details.health);

 console.log("-------------------------------------------------");
 });
 };

 function login(){
 request(
 {
 url: "http://" + ip + ":" + port + "/game/" + game_id + "/player/",
 method: "POST",
 json: true,
 body: login_data
 },
 function (error, response, body){

 console.log("\nLOGGING IN \n");

 user_details.name = body.result.name;
 user_details.id = body.result.id;
 user_details.health = body.result.health;

 console.log("We're logged in and got our details: \n");

 console.log("ID: " + user_details.id);
 console.log("Name: " + user_details.name);
 console.log("Health: " + user_details.health);

 console.log("-------------------------------------------------");
 });
 };*/

function getAmmo(){
	
	$.ajax({
        type : 'GET',
        url : "http://" + ip + ":" + port + "/game/" + game_id + "/player/" + player_id + "/ammo",
        async : true,
        success : function(data){
			
			console.log("\nGETTING AMMO\n");

            var body = data;//JSON.parse(data);

            if(body.result == "OK"){
                console.log("We've got some ammo.\n");
            }else if (body.result == "NOK"){
                console.log("We can't get any ammo.\n");
            }

            console.log("-------------------------------------------------");
        },
        error : function(XMLHttpRequest, textStatus, errorThrown){
			
        }
    });
	
	
    /*request(
        {
            url: "http://" + ip + ":" + port + "/game/" + game_id + "/player/" + player_id + "/ammo",
            method: "GET"
        },
        function (error, response, body){

            console.log("\nGETTING AMMO\n");

            var bodyParsed = JSON.parse(body);

            if(body.result == "OK"){
                //queue = true;
                //user_details.ammo.hit = bodyParsed.ammo.hit;

                console.log("We've got some ammo.\n");
            }else if (bodyParsed.result == "NOK"){
                //queue = false;
                //user_details.ammo.hit = 0;

                console.log("We can't get any ammo.\n");
            }

            console.log("Hit: " + user_details.ammo.hit);

            console.log("-------------------------------------------------");
        });*/
}

function shoot(){
	
    fire();
	
	$.ajax({
		type: 'POST',
		url: "http://" + ip + ":" + port + "/game/" + game_id + "/player/" + player_id + "/ammo",
		async: true,
		contentType: "application/json",
		dataType: 'json',
		success:
			function(data) {
				console.log('Robot fires a shot');
			},
		error:
			function(XMLHttpRequest, textStatus, errorThrown) {
			
			}
	});
	
    /*request(
        {
            url: "http://" + ip + ":" + port + "/game/" + game_id + "/player/" + player_id + "/ammo",
            method: "POST",
            json: true
        },
        function (error, response, body){
            console.log('Robot fires a shot');
        });*/
}