import React, { useState } from "react";

import Buttons from "./Components/Buttons";
import MealCardHolder from "./Components/MealCardHolder";

let appData = [
  {
    name: "Meal 1",
    description: "Description 1",
    imageSource: "https://picsum.photos/id/200/200",
    type: "Breakfast",
  },
  {
    name: "Meal 2",
    description: "Description 2",
    imageSource: "https://picsum.photos/id/201/200",
    type: "Lunch",
  },
  {
    name: "Meal 3",
    description: "Description 3",
    imageSource: "https://picsum.photos/id/202/200",
    type: "Lunch",
  },
  {
    name: "Meal 4",
    description: "Description 4",
    imageSource: "https://picsum.photos/id/203/200",
    type: "Dinner",
  },
  {
    name: "Meal 5",
    description: "Description 5",
    imageSource: "https://picsum.photos/id/204/200",
    type: "Lunch",
  },
  {
    name: "Meal 6",
    description: "Description 6",
    imageSource: "https://picsum.photos/id/277/200",
    type: "Breakfast",
  },
  {
    name: "Meal 7",
    description: "Description 8",
    imageSource: "https://picsum.photos/id/206/200",
    type: "Dinner",
  },
  {
    name: "Meal 8",
    description: "Description 8",
    imageSource: "https://picsum.photos/id/267/200",
    type: "Lunch",
  },
  {
    name: "Meal 9",
    description: "Description 9",
    imageSource: "https://picsum.photos/id/208/200",
    type: "Dinner",
  },
  {
    name: "Meal 10",
    description: "Description 10",
    imageSource: "https://picsum.photos/id/209/200",
    type: "Dinner",
  },
];

const App = () => {
  const [currentMeal, setCurrentMeal] = useState("Breakfast");
  const buttonClickHandler = (event) => {
    setCurrentMeal(event.target.innerText);
  };

  let filteredArray = appData;
  if (currentMeal != "All") {

    filteredArray = appData.filter((meal) => {
      return meal.type === currentMeal;
    });

  }

  return (
    <div className="container">
      <Buttons onClick={buttonClickHandler} />
      <MealCardHolder meals={filteredArray} />
    </div>
  );
};

export default App;
