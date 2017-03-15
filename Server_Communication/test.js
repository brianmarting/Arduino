var request = require('request');

var user_details = {
	id: '',
	name: '',
	health: ''
};

var login_data = { 
	'name':'Terminator6'
};

var queue = false;

function login(){
	request(
	{
		url: "http://172.31.41.35:3000/game/0/player/",
		method: "POST",
		json: true,
		body: login_data
	},
		function (error, response, body){
    		var doc = JSON.parse(response);
			user_details.name = doc.name;
			user_details.id = doc.name;
			user_details.health = doc.health;
			console.log("We're logged in and got our details");
		});
};

function getAmmo(){
	request(
	{
		url: "http://172.31.41.35:3000/game/0/player/" + user_details.id + "/ammo",
		method: "GET"
	},
		function (error, response, body){
    		if(response == 'OK'){
				queue = true;
				console.log("We've got some ammo");
			}else{
				queue = false;
			}
		});
}

function fire(){
	if(queue == true){
		request(
			{
				url: "http://172.31.41.35:3000/game/0/player/" + user_details.id + "/ammo",
				method: "POST",
				json: true
			},
				function (error, response, body){
					console.log('Robot fires a shot');
					robot_shoot();
				});
	}
}

// our robot got hit
// damage is done 
function hit(){
	if(robot_receivedShot() == true){
		request(
			{
				url: "http://172.31.41.35:3000/game/0/player/" + user_details.id + "/hit",
				method: "POST",
				json: true
			},
				function (error, response, body){
					console.log('We got hit and damage is done');
				});
	}
	
}

function robot_receivedShot(){
	
}

function robot_shoot(){
	
}

