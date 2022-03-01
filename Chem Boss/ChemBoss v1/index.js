//add urls to go to once an element is clicked

let title = document.getElementById("title-container").getElementsByTagName("p")[0];
title.addEventListener("click",()=>{window.location="./index.html"});

let quizTiles = document.getElementsByClassName("quiz-tile");
quizTiles[0].addEventListener("click",()=>{window.location="./atomic-number-quiz.html"});
quizTiles[1].addEventListener("click",()=>{window.location="./GamesPages/index.html"});

