import React from "react";

import "./QuizScreen.css";
//here props will receive two things questionObject number and points
const QuizScreen = (props) => {
  return (
    <div className="quiz-screen">
      <div className="quiz-banner">
        <p>{`Points:${props.points}`}</p>
        <p>{`Question Number:${props.questionNumber + 1}`}</p>
      </div>

      <p className="question">{props.questionObject.question}</p>
      <div className="options">
        <p
          className="option"
          data-option-number="a"
          onClick={props.onOptionClick}
        >
          {props.questionObject.answers.a}
        </p>
        <p
          className="option"
          data-option-number="b"
          onClick={props.onOptionClick}
        >
          {props.questionObject.answers.b}
        </p>
        <p
          className="option"
          data-option-number="c"
          onClick={props.onOptionClick}
        >
          {props.questionObject.answers.c}
        </p>
      </div>
    </div>
  );
};

export default QuizScreen;
