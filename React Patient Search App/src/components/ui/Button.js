import React from "react";

const Button = (props) => {
  return (
    <button
      className={props.className}
      type={props.type}
      onClick={props.onClick}
      disabled={props.disabled}
      data-id={props.dataID}
    >
      {props.name}
    </button>
  );
};

export default Button;
