import React from "react";

import "./ListItem.css";

const ListItem = (props) => {
  console.log(props.id)
  return (
    <li data-id={props.id}>
      <p>{props.data.task}</p>
      <i onClick={props.cancelItemHandler} className="fas fa-times"></i>
    </li>
  );
};

export default ListItem;
