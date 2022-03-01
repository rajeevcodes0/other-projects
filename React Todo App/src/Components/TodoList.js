import React from "react";

import ListItem from "./ListItem";
import "./TodoList.css";

const TodoList = (props) => {
  return (
    <ul>
      {props.data.map((taskObject) => {
        return (
          <ListItem
            key={taskObject.id}
            id={taskObject.id}
            cancelItemHandler={props.cancelItemHandler}
            data={taskObject}
          />
        );
      })}
    </ul>
  );
};

export default TodoList;
