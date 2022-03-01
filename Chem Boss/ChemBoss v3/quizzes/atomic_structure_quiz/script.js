//adding link to title
let title = document.getElementById("header").getElementsByTagName("p")[0];
title.addEventListener("click",()=>{window.location="../../index.html"});

//to store difficulty
let difficulty = "not selected";
//array that holds the question, answer, and options

let easyQuestions=[
    {
        statement:"نماد عنصر لیتیم چیست؟",
        options:["La", "Li", "Lu", "Lr"],
        answer:"Li"
        },
        {
        statement:"چه تعداد پروتون در هسته اتم  کربن وجود دارد؟",
        options:["8", "7", "5", "6"],
        answer:"6"
        },
        {
        statement:"کدامیک نماد عنصری خنثی است؟",
        options:["Al<sup>3+</sup>", "Al<sup>2+</sup>", "Al<sup>+</sup>", "Al<sup>0</sup>"],
        answer:"Al<sup>0</sup>"
        },
        {
        statement:'تعداد الکترون کدام نماد از تعداد پروتون آن بیشتر است؟',
        options:["C<sup>4+</sup>", "C", "Si<sup>4+</sup>", "Si<sup>4-</sup>"],
        answer:"Si<sup>4-</sup>"
        },
        {
        statement:"کدام نماد صحیح نیست؟",
        options:["<sup>3</sup>H<sup>1+</sup>", "<sup>2</sup>H<sup>1+</sup>", "<sub>2</sub>H<sup>1+</sup>", "<sup>2</sup>H<sup>2+</sup>"],
        answer:"<sup>2H<sup>2+"
        },
        {
        statement:"کدام اتم در حالت گازی وجود ندارد؟",
        options:["N", "Ne", "Na", "He"],
        answer:"Na"
        },
        {
        statement:"عدد اتمی کدام عنصر 11 است؟",
        options:["N", "Ne", "Na", "Nb"],
        answer:"Na"
        },
        {
        statement:"تعداد نوترون های کربن-13 چند است؟",
        options:["6", "7", "12", "13"],
        answer:"7"
        },
        {
        statement:"عدد جرمی چگونه محاسبه می شود؟",
        options:["پروتون+نوترون", "پروتون+الکترون", "نوترون+الکترون", "پروتون-الکترون"],
        answer:"پروتون+نوترون"
        },
        {
        statement:"عدد اتمی آلومینیم چند است؟",
        options:["11", "12", "13", "14"],
        answer:"13"
        },
        {
        statement:"در کدام نماد 6 نوترون وجود دارد؟",
        options:["<sub>5</sub>B", "<sup>10</sup>B", "<sub>6</sub>B", "<sup>11</sup>B"],
        answer:"<sup>11</sup>B"
        },
        {
        statement:"کدام نماد تعداد الکترون بیشتری دارد؟",
        options:["Mn<sup>2+</sup>", "Mn<sup>3+</sup>", "Mn<sup>4+</sup>", "Mn<sup>6+</sup>"],
        answer:"Mn<sup>2+</sup>"
        },
        {
        statement:"کدام نماد یک آنیون است؟",
        options:["H<sup>2+</sup>", "H<sup>1+</sup>", "H<sup>0</sup>", "H<sup>1-</sup>"],
        answer:"H<sup>1-</sup>"
        },
        {
        statement:"تعداد پروتون های کدام اتم 17 است؟",
        options:["F", "Cl", "Br", "I"],
        answer:"Cl"
        },
        {
        statement:"تعدا پروتون های کدام نماد 23 است؟",
        options:["<sub>23</sub>V", "<sup>23</sup>Na", "<sub>24</sub>Mg<sup>2+</sup>", "<sub>24</sub>Mn<sup>2+</sup>"],
        answer:"<sub>23</sub>V"
        }
];
let hardQuestions=[
        {
        statement:"در کدام نماد 6 نوترون می تواند وجود داشته باشد؟",
        options:["<sup>5</sup>B", "<sub>5</sub>B", "<sub>6</sub>B", "<sup>10</sup>B"],
        answer:"<sub>5</sub>B"
        },
        {
        statement:"کدام نماد تعداد الکترون کمتری دارد؟",
        options:["Fe<sup>2+</sup>", "Co<sup>2+</sup>", "Ni<sup>3+</sup>", "Mn<sup>0</sup>"],
        answer:"Fe<sup>2+</sup>"
        },
        {
        statement:"تعداد الکترون های کدام نماد متفاوت است؟",
        options:["As<sup>3-</sup>", "Se<sup>2-</sup>", "Br<sup>-</sup>", "Ge"],
        answer:"Ge"
        },
        {
        statement:"کدام اتم 28 الکترون دارد؟",
        options:["Cu<sup>+</sup>", "Cu<sup>2+</sup>", "Zn<sup>2+</sup>", "Ga<sup>3+</sup>"],
        answer:"Cu<sup>+</sup>"
        },
        {
        statement:"تعداد الکترون های کدام نماد با آرگون برابر نیست؟",
        options:["S<sup>2-</sup>", "Cl<sup>-</sup>", "K<sup>+</sup>", "Ti<sup>3+</sup>"],
        answer:"Ti<sup>3+</sup>"
        },
        {
        statement:"تعداد الکترون های کدام نماد متفاوت است؟",
        options:["O<sup>-</sup>", "Ne", "Na<sup>+</sup>", "Mg<sup>2+</sup>"],
        answer:"O<sup>-</sup>"
        },
        {
        statement:"کدام نماد نوترون بیشتری دارد؟",
        options:["<sup>64</sup>Zn", "<sup>68</sup>Zn", "<sup>65</sup>Cu", "<sup>69</sup>Ga"],
        answer:"<sup>68</sup>Zn"
        },
        {
        statement:"کدام نماد الکترون بیشتری دارد؟",
        options:["<sup>64</sup>Zn", "<sup>68</sup>Zn", "<sup>65</sup>Cu", "<sup>69</sup>Ga"],
        answer:"<sup>69</sup>Ga"
        },
        {
        statement:"تعداد الکترون کدام نماد متفاوت است؟",
        options:["H<sup>+</sup>", "He", "Li<sup>+</sup>", "Be<sup>2+</sup>"],
        answer:"H<sup>+</sup>"
        },
        {
        statement:"تعداد الکترون های کدام نماد 19 است؟",
        options:["Cl<sup>-</sup>", "K<sup>+</sup>", "Ca<sup>2+</sup>", "Ti<sup>3+</sup>"],
        answer:"Ti<sup>3+</sup>"
        }
];
let questions=[
        {
        statement:"نماد عنصر لیتیم چیست؟",
        options:["La", "Li", "Lu", "Lr"],
        answer:"Li"
        },
        {
        statement:"چه تعداد پروتون در هسته اتم  کربن وجود دارد؟",
        options:["8", "7", "5", "6"],
        answer:"6"
        },
        {
        statement:"کدامیک نماد عنصری خنثی است؟",
        options:["Al<sup>3+</sup>", "Al<sup>2+</sup>", "Al<sup>+</sup>", "Al<sup>0</sup>"],
        answer:"Al<sup>0</sup>"
        },
        {
        statement:"تعداد الکترون کدام نماد از تعداد پروتون آن بیشتر است؟",
        options:["C<sup>4+</sup>", "C", "Si<sup>4+</sup>", "Si<sup>4-</sup>"],
        answer:"Si<sup>4-</sup>"
        },
        {
        statement:"کدام نماد صحیح نیست؟",
        options:["<sup>3</sup>H<sup>1+</sup>", "<sup>2</sup>H<sup>1+</sup>", "<sub>2</sub>H<sup>1+</sup>", "<sup>2</sup>H<sup>2+</sup>"],
        answer:"<sup>2 H <sup>2+"
        },
        {
        statement:"کدام اتم در حالت گازی وجود ندارد؟",
        options:["N", "Ne", "Na", "He"],
        answer:"Na"
        },
        {
        statement:"عدد اتمی کدام عنصر 11 است؟",
        options:["N", "Ne", "Na", "Nb"],
        answer:"Na"
        },
        {
        statement:"تعداد نوترون های کربن-13 چند است؟",
        options:["6", "7", "12", "13"],
        answer:"7"
        },
        {
        statement:"عدد جرمی چگونه محاسبه می شود؟",
        options:["پروتون+نوترون", "پروتون+الکترون", "نوترون+الکترون", "پروتون-الکترون"],
        answer:"پروتون+نوترون"
        },
        {
        statement:"عدد اتمی آلومینیم چند است؟",
        options:["11", "12", "13", "14"],
        answer:"13"
        },
        {
        statement:"در کدام نماد 6 نوترون وجود دارد؟",
        options:["<sub>5</sub>B", "<sup>10</sup>B", "<sub>6</sub>B", "<sup>11</sup>B"],
        answer:"<sup>11</sup>B"
        },
        {
        statement:"کدام نماد تعداد الکترون بیشتری دارد؟",
        options:["Mn <sup>2+</sup>", "Mn <sup>3+</sup>", "Mn <sup>4+</sup>", "Mn <sup>6+</sup>"],
        answer:"Mn <sup>2+</sup>"
        },
        {
        statement:"کدام نماد یک آنیون است؟",
        options:["H <sup>2+</sup>", "H <sup>1+</sup>", "H <sup>0</sup>", "H <sup>1-</sup>"],
        answer:"H <sup>1-"
        },
        {
        statement:"تعداد پروتون های کدام اتم 17 است؟",
        options:["F", "Cl", "Br", "I"],
        answer:"Cl"
        },
        {
        statement:"تعدا پروتون های کدام نماد 23 است؟",
        options:["<sub>23</sub>V", "<sup>23</sup>Na", "<sub>24</sub>Mg<sup>2+</sup>", "<sub>24</sub>Mn<sup>2+</sup>"],
        answer:"<sub>23</sub>V"
        }
];

let currentQuestionNumber=0;

let points=0;

//assigning actions to buttons
let buttons = document.getElementsByTagName("button");

buttons[0].addEventListener("click",()=>{
    difficulty="easy";
    prepareQuestions();
    //console.log(questions);
    startQuiz();
})

buttons[1].addEventListener("click",()=>{
    difficulty="difficult";
    prepareQuestions();
    //console.log(questions);
    startQuiz();
    
})


//function to prepare questions array
function prepareQuestions(){
    currentQuestionNumber=0;
    if(difficulty=="easy"){

        questions=easyQuestions;

    }else{

        questions=hardQuestions;       
    }
    console.log(questions);
    //randomizing questions
    let shuffleArray = [];
    let remaining = 10;
    let range=0;
    if(difficulty=='easy'){
        range=15;
    }else{
        range=10;
    }
    while(remaining>0){
        
        let randomQuestion = Math.floor(Math.random()*range);
        if(questions[randomQuestion]!='*'){
            shuffleArray.push(questions[randomQuestion]);
            questions[randomQuestion]='*';
            remaining--;
        }
    }
    questions=shuffleArray;
    console.log(questions);

    let shuffleOptions = [];
    console.log(shuffleOptions);
}


function startQuiz(){
    //first remove the difficulty holder div
    let elementToRemove = document.getElementsByClassName("select-difficulty")[0];
    elementToRemove.parentNode.removeChild(elementToRemove);

    //add points
    let pointsHolder = document.createElement("p");
    pointsHolder.innerText=0;
    pointsHolder.className="points-holder";
    document.getElementById("question-card").appendChild(pointsHolder);

    let questionStatement = document.createElement('p');
    questionStatement.className="question-statement";
    questionStatement.innerHTML=questions[0].statement;

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

    



    document.getElementById("question-card").appendChild(questionStatement);

    document.getElementById("question-card").appendChild(optionOne);

    document.getElementById("question-card").appendChild(optionTwo);

    document.getElementById("question-card").appendChild(optionThree);

    document.getElementById("question-card").appendChild(optionFour);
}

function nextQuestion(questionNumber){
    let questionStatement = document.getElementsByClassName("question-statement")[0];
    let options = document.getElementsByClassName("option");

    questionStatement.innerHTML = questions[questionNumber].statement;
    options[0].innerHTML=questions[questionNumber].options[0];
    options[1].innerHTML=questions[questionNumber].options[1];
    options[2].innerHTML=questions[questionNumber].options[2];
    options[3].innerHTML=questions[questionNumber].options[3];
}

function verifyAnswer(e){
    let clicked;
    console.log("verifying");
    console.log("clicked");
    console.log(e.target.innerHTML);
    console.log("the answer");
    console.log(questions[currentQuestionNumber].answer);

    console.log("experiment");
    console.log(e.target.parentNode.innerHTML);

    //to make sure subscript is not clicked
    if(e.target.parentNode.id!="question-card"){
        console.log("question-card is not parent");
        clicked = e.target.parentNode.innerHTML;
    }else{
        console.log("question-card is parent");
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
        let questionCard = document.getElementById("question-card");
        questionCard.innerHTML="";

        let theEndMessage = document.createElement('p');
        theEndMessage.className = "the-end-message";
        theEndMessage.innerText =`${points} پایان آزمون! نمره شما`;
        
        let homeButton = document.createElement("button");
        homeButton.className="home-button";
        homeButton.innerText="بازگشت";

        homeButton.addEventListener("click",()=>{
            window.location="index.html";
        })

        questionCard.appendChild(theEndMessage);
        questionCard.appendChild(homeButton);

    }
}