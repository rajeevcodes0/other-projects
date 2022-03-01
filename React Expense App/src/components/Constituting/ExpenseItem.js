//importing libraries
import React from "react";

//importing hooks
import { useContext, useState } from "react";

//importing stylesheets
import classes from "./ExpenseItem.module.css";

//importing app context
import AppData from "../../store/app-data";

//import UI components
import Card from "../UI/Card";
import Button from "../UI/Button";

const ExpenseItem = (props) => {
  console.log("rendering ExpenseItem component");
  const appData = useContext(AppData);

  //the following state will be used to show animation

  const [isItemBeingDeleted, setIsItemBeingDeleted] = useState(false);

  let selectedThemeClass = "";
  let selectedThemeClassFa = "";
  if (appData.selectedTheme === "dark") {
    selectedThemeClass = "dark-mode-theme";
  } else if (appData.selectedTheme === "light") {
    selectedThemeClass = "light-mode-theme";
  } else if (appData.selectedTheme === "violet") {
    selectedThemeClass = "violet-mode-theme";
  }
  selectedThemeClassFa= selectedThemeClass+"-fa";

  //earlier I declared this function inside the button component,
  //but it was interfearing with other buttons as well.
  const deleteLogHandler = (e) => {
    if (e.target.nodeName === "BUTTON") {
      setIsItemBeingDeleted(true);
      setTimeout(() => {
        appData.deleteLogHandler(e.target.dataset.itemid);
      }, 500);
    } else if (e.target.nodeName == "I") {
      setIsItemBeingDeleted(true);
      setTimeout(() => {
        appData.deleteLogHandler(e.target.parentNode.dataset.itemid);
      }, 500);
    }
    //props.onClick(e.target);
    console.log("Hello im clicked");
  };

  return (
    <Card>
      <div
        className={`${classes["expense-item-container"]} ${classes[selectedThemeClass]} ${
          isItemBeingDeleted ? classes["item-being-deleted"] : ""
        }`}
      >
        <div className={classes["expense-item-info"]}>
          <p>{props.title}</p>
          <p>{`${appData.currencySymbol} ${props.amount}`}</p>
        </div>
        <div className={classes["expense-item-controls"]}>
          <Button
            itemID={props.id}
            title={<i className={`${"fas fa-pen"} ${classes[selectedThemeClassFa]}`}></i>}
            className={classes["button-edit"]}
          ></Button>
          <Button
            itemID={props.id}
            title={<i className={`${"fas fa-trash-alt"} ${classes[selectedThemeClassFa]}`}></i>}
            className={classes["button-delete"]}
            onClick={deleteLogHandler}
          ></Button>
        </div>
      </div>
    </Card>
  );
};

export default ExpenseItem;

/*
NOTE:
We provide itemID to the buttons so that when they are clicked, we can identify the expense that was clicked


*/
