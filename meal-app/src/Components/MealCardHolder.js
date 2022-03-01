import React from "react";

import '../Stylesheets/MealCardHolder.css';

import Card from "./Card";


const MealCardHolder = (props) => {
  return (
    <div className="meal-card-holder">
      {props.meals.map((meal) => {
        return (
          
            <Card
              name={meal.name}
              description={meal.description}
              imageSource={meal.imageSource}
            />
          
        );
      })}
    </div>
  );
};

export default MealCardHolder;
