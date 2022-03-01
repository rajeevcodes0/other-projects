////importing libraries
import React from "react";

//importing stylesheet
import classes from "./Input.module.css";

const Input = (props) => {
  return (
    <div className={classes.input}>
      <label htmlFor={props.id}>{props.value}</label>
      <input type={props.type} id={props.id}></input>
    </div>
  );
};

export default Input;
