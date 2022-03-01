//adding link to title
let title = document.getElementById("title-container").getElementsByTagName("p")[0];
title.addEventListener("click",()=>{window.location="../../index.html"});
//database
let questions=[
    {
        image:"assets/01.jpg",
        statement:"این نماد چه عنصری است؟",
        options:["لانتانیم", "لیتیم", "لوتنیم", "لورنزیم"],
        answer:"لیتیم"
        },
        {
        image:"assets/02.jpg",
        statement:"این نماد چه عنصری می تواند باشد؟",
        options:["تریتیم", "دوتریم", "پروتیم", "هلیم"],
        answer:"تریتیم"
        },
        {
        image:"assets/03.jpg",
        statement:"این عنصر چه تعداد نوترون دارد؟",
        options:["8", "6", "11", "5"],
        answer:"6"
        },
        {
        image:"assets/04.jpg",
        statement:"این نماد یک نمونه ... است؟",
        options:["کاتیون", "آنیون", "خنثی", "هیچکدام"],
        answer:"کاتیون"
        },
        {
        image:"assets/05.jpg",
        statement:"تعداد الکترون های این نماد با کدام عنصر برابر است؟",
        options:["Ne", "Na", "Mg", "F"],
        answer:"Ne"
        },
        {
        image:"assets/06.jpg",
        statement:"این عنصر چه تعداد پروتون دارد؟",
        options:["15", "10", "16", "18"],
        answer:"15"
        },
        {
        image:"assets/07.jpg",
        statement:"این کاتیون چه باری دارد؟",
        options:["1+", "2+", "3+", "4+"],
        answer:"3+"
        },
        {
        image:"assets/08.jpg",
        statement:"تعداد الکترون های این نماد با کدام نمونه برابر است؟",
        options:["Na", "F", "Ar", "Ne"],
        answer:"Ne"
        },
        {
        image:"assets/09.jpg",
        statement:"این نماد چه تعداد الکترون دارد؟",
        options:["14", "15", "18", "29"],
        answer:"18"
        },
        {
        image:"assets/10.jpg",
        statement:"این نماد چه تعداد نوترون دارد؟",
        options:["16", "17", "18", "33"],
        answer:"17"
        }
];

let points = 0;
let currentQuestionNumber = 0;


function startQuiz(){

    //randomize the questions
    let shuffleArray = [];
    let remaining = 10;
    while(remaining>0){
        
        let randomQuestion = Math.floor(Math.random()*10);
        if(questions[randomQuestion]!='*'){
            shuffleArray.push(questions[randomQuestion]);
            questions[randomQuestion]='*';
            remaining--;
        }
    }
    questions=shuffleArray;
    console.log(questions);

    //for adding points
    let pointsHolder = document.createElement("p");
    pointsHolder.innerText=0;
    pointsHolder.className="points-holder";
    document.getElementsByTagName("body")[0].appendChild(pointsHolder);

    //insert image, question and options
    let image = document.createElement("img");
    image.src = questions[0].image;
    image.className="question-image";
    document.getElementsByTagName("body")[0].appendChild(image);

    let questionHolder = document.createElement('div');
    questionHolder.className="question-holder";
    document.getElementsByTagName("body")[0].appendChild(questionHolder);

    let questionStatement = document.createElement('p');
    questionStatement.className="question-statement";
    questionStatement.innerHTML=questions[0].statement;
    questionHolder.appendChild(questionStatement);

    let optionOne = document.createElement('p');
    optionOne.className="option";
    optionOne.addEventListener("click",verifyAnswer);
    optionOne.innerHTML=questions[0].options[0];

    let optionTwo = document.createElement('p');
    optionTwo.className="option";
    optionTwo.addEventListener("click",verifyAnswer);
    optionTwo.innerHTML=questions[0].options[1];

    let optionThree = document.createElement('p');
    optionThree.className="option";
    optionThree.addEventListener("click",verifyAnswer);
    optionThree.innerHTML=questions[0].options[2];

    let optionFour = document.createElement('p');
    optionFour.className="option";
    optionFour.addEventListener("click",verifyAnswer);
    optionFour.innerHTML=questions[0].options[3];

    questionHolder.appendChild(optionOne);
    questionHolder.appendChild(optionTwo);
    questionHolder.appendChild(optionThree);
    questionHolder.appendChild(optionFour);

}

function verifyAnswer(e){
    let clicked;
    // console.log("verifying");
    // console.log("clicked");
    // console.log(e.target.innerHTML);
    // console.log("the answer");
    // console.log(questions[currentQuestionNumber].answer);

    // console.log("experiment");
    // console.log(e.target.parentNode.innerHTML);

    //to make sure subscript is not clicked
    if(e.target.parentNode.className!="question-holder"){
        console.log("question-holder is not parent");
        clicked = e.target.parentNode.innerHTML;
    }else{
        console.log("question-holder is parent");
        clicked = e.target.innerHTML;
    }
    //clicked variable
    console.log(clicked);
    console.log("after changes");
    console.log(e.target.innerHTML);
    console.log(questions[currentQuestionNumber].answer);
    /////////////////////////////////////////////////////////
    if(currentQuestionNumber==10){
        console.log('returning');
        return;
    }
    if(clicked==questions[currentQuestionNumber].answer){
        console.log("bingo");
        points++;
        console.log(points);
        document.getElementsByClassName("points-holder")[0].innerText=points;
        console.log("score updated");
    }
    currentQuestionNumber++;
    if(currentQuestionNumber<10){
        nextQuestion(currentQuestionNumber);
    }else{
        let body = document.getElementsByTagName("body")[0];
        let image = document.getElementsByClassName("question-image")[0];
        let questionHolder = document.getElementsByClassName("question-holder")[0];
        body.removeChild(image);
        body.removeChild(questionHolder);


        let theEndMessage = document.createElement('p');
        theEndMessage.className = "the-end-message";
        theEndMessage.innerText =`${points} پایان آزمون! نمره شما`;
        
        let homeButton = document.createElement("button");
        homeButton.className="home-button";
        homeButton.innerText="بازگشت";

        homeButton.addEventListener("click",()=>{
            window.location="../../index.html";
        })

        body.appendChild(theEndMessage);
        body.appendChild(homeButton);

    }
}

function nextQuestion(questionNumber){
    let questionStatement = document.getElementsByClassName("question-statement")[0];
    let options = document.getElementsByClassName("option");

    let questionImage = document.getElementsByClassName("question-image")[0];

    questionImage.src=questions[questionNumber].image;
    questionStatement.innerHTML = questions[questionNumber].statement;
    options[0].innerHTML=questions[questionNumber].options[0];
    options[1].innerHTML=questions[questionNumber].options[1];
    options[2].innerHTML=questions[questionNumber].options[2];
    options[3].innerHTML=questions[questionNumber].options[3];
}

//starting the quiz
startQuiz();