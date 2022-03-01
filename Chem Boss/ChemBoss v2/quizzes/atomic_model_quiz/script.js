//adding link to title
let title = document.getElementById("title-container").getElementsByTagName("p")[0];
title.addEventListener("click",()=>{window.location="../../index.html"});

//database
let questions=[
        {
        image:"assets/1.jpg",
        statement:"نماد این اتم چیست؟",
        options:["H<sup>1+</sup>", "H<sup>2+</sup>", "H<sup>1-</sup>", "H<sup>2-</sup>"],
        answer:"H<sup>1-</sup>"
        },
        {
        image:"assets/2.jpg",
        statement:"این عنصر چیست؟",
        options:["H<sup>2-</sup>", "He<sup>2+</sup>", "Be<sup>2+</sup>", "He<sup>0</sup>"],
        answer:"He<sup>0</sup>"
        },
        {
        image:"assets/3.jpg",
        statement:"این شکل مربوط به کدام نماد است؟",
        options:["Li<sup>+</sup>", "He<sup>2+</sup>", "He<sup>-</sup>", "Be<sup>+</sup>"],
        answer:"Li<sup>+</sup>"
        },
        {
        image:"assets/4.jpg",
        statement:"کدام نماد با ساختار این اتم مطابقت دارد؟",
        options:["<sub>6</sub>B", "<sup>10</sup>B", "<sup>11</sup>B", "B<sup>+</sup>"],
        answer:"<sup>11</sup>B"
        },
        {
        image:"assets/5.jpg",
        statement:"کدام نماد صحیح است؟",
        options:["B<sup>0</sup>", "B<sup>+</sup>", "B<sup>2+</sup>", "B<sup>3+</sup>"],
        answer:"B<sup>3+</sup>"
        },
        {
        image:"assets/6.jpg",
        statement:"این ساختار کدام اتم است؟",
        options:["Ne", "Na", "Mg", "Al"],
        answer:"Mg"
        },
        {
        image:"assets/7.jpg",
        statement:"این ساختار مربوط به کدام نماد است؟",
        options:["Na<sup>+</sup>", "Na<sup>0</sup>", "Mg<sup>2+</sup>", "Ne"],
        answer:"Na<sup>0</sup>"
        },
        {
        image:"assets/8.jpg",
        statement:"نماد این ساختار چیست؟",
        options:["<sup>6</sup>Li", "<sup>7</sup>Li", "Li<sup>+</sup>", "Be<sup>+</sup>"],
        answer:"<sup>7</sup>Li"
        },
        {
        image:"assets/9.jpg",
        statement:"کدام نماد صحیح است؟",
        options:["<sup>2</sup>He", "Li<sup>+</sup>", "<sup>1</sup>He", "<sup>3</sup>He"],
        answer:"<sup>3</sup>He"
        },
        {
        image:"assets/10.jpg",
        statement:"نماد این ساختار کدام است؟",
        options:["<sub>5</sub>Be<sup>+</sup>", "<sub>4</sub>Be<sup>+</sup>", "<sup>9</sup>Be<sup>+</sup>", "<sup>9</sup>Be<sup>2+</sup>"],
        answer:"<sup>9</sup>Be<sup>2+</sup>"
        }
]

let points = 0;
let currentQuestionNumber = 0;


let startQuizButton = document.getElementById("start-quiz");
startQuizButton.addEventListener('click',startQuiz);

function startQuiz(){
    //remove hint and start button
    let hintImage = document.getElementById("hint");
    //we already have startQuizButton
    let parent = document.getElementsByTagName("body")[0];
    parent.removeChild(hintImage);
    parent.removeChild(startQuizButton);

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