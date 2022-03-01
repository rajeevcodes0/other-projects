//add urls to go to once an element is clicked

let title = document.getElementById("header").getElementsByTagName("p")[0];
title.addEventListener("click",()=>{window.location="./index.html"});

let quizTiles = document.getElementsByClassName("quiz-tile");
quizTiles[0].addEventListener("click",()=>{window.location="./quizzes/atomic_model_quiz/index.html"});
quizTiles[1].addEventListener("click",()=>{window.location="./quizzes/atomic_symbol_quiz/index.html"});
quizTiles[2].addEventListener("click",()=>{window.location="./quizzes/atomic_structure_quiz/index.html"});

