import React from "react";
import InputForm from "./InputForm";

const InputControl = (props) => {
  return (
    <InputForm
      onAddTask={props.onAddTask}
      onInputChange={props.onInputChange}
      inputValue = {props.inputValue}
    />
  );
};

export default InputControl;
