import React, { useState } from "react";

import data from "../assets/questions.json";

import "./Container.css";

import StartScreen from "./StartScreen";
import QuizScreen from "./QuizScreen";
import EndScreen from "./EndScreen";

const Container = () => {
  let content = "";
  const [playerName, setPlayerName] = useState("");
  const [screenName, setScreenName] = useState("start-screen");
  const [questionNumber, setQuestionNumber] = useState(0);
  const [points, setPoints] = useState(0);

  const submitHandler = (event) => {
    event.preventDefault();
    setPlayerName(event.target[0].value);
    setScreenName("quiz-screen");
  };

  const optionClickHandler = (event) => {
    console.log(event.target.dataset.optionNumber);
    console.log(data[questionNumber].answers.correct);
    if (
      event.target.dataset.optionNumber == data[questionNumber].answers.correct
    ) {
      setPoints((prevState) => {
        return prevState + 1;
      });
    }

    setQuestionNumber((prevState) => {
      return prevState + 1;
    });
    if (questionNumber > 8) {
      setScreenName("end-screen");
    }
  };

  if (screenName == "start-screen") {
    content = <StartScreen onSubmit={submitHandler} />;
  } else if (screenName == "quiz-screen") {
    content = (
      <QuizScreen
        points={points}
        questionNumber={questionNumber}
        questionObject={data[questionNumber]}
        onOptionClick={optionClickHandler}
      />
    );
  } else {
    content = <EndScreen playerName={playerName} points={points} />;
  }

  return <div className="container">{content}</div>;
};

export default Container;
