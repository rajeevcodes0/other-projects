var audio = new Audio("http://yellowfunction.tech/a.mp3");
let searchButton = document.getElementsByClassName("pin-search-btn district-search")[0];

function checker(){
	searchButton.click();
	let age45 = document.getElementsByClassName("form-check-label")[1];
	age45.click();
	let hospitals = document.getElementsByClassName("row ng-star-inserted");

	let hospitalOfChoice="";
	for(let i=0;i<hospitals.length;i++){
		if(hospitals[i].getElementsByClassName("center-name-title")[0].innerText=="AIR FORCE HOSPITAL"){
			hospitalOfChoice = hospitals[i];
		}

	}

	let slotUl = hospitalOfChoice.getElementsByClassName("slot-available-wrap")[0]; 
	let slotUlLi = slotUl.getElementsByTagName("li");
	let liOfChoice = slotUlLi[1];

	console.log(liOfChoice.innerText);
	//console.log(liOfChoice);



	let vaccineCount = parseInt(liOfChoice.getElementsByTagName("a")[0].innerText);

	if(vaccineCount>0){
		audio.play();
	}	
}

setInterval(checker,10000);