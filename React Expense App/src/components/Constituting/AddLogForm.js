//importing libraries
import React from "react";

//importing stylesheets
import classes from "./AddLogForm.module.css";

//importing context
import AppData from "../../store/app-data";

//importing hooks
import { useState, useContext } from "react";

//importing UI constituting components
import Button from "../UI/Button";
import Input from "../UI/Input";

const AddLogForm = (props) => {
  console.log("rendering AddLogForm component");
  const appData = useContext(AppData);
  console.log(appData);

  const [expenseType, setExpenseType] = useState("income");

  const changeExpenseTypeToIncome = () => {
    setExpenseType("income");
  };

  const changeExpenseTypeToExpense = () => {
    setExpenseType("expense");
  };

  let selectedThemeClass = "";
  if (appData.selectedTheme === "dark") {
    selectedThemeClass = "dark-mode-theme";
  } else if (appData.selectedTheme === "light") {
    selectedThemeClass = "light-mode-theme";
  } else if (appData.selectedTheme === "violet") {
    selectedThemeClass = "violet-mode-theme";
  }
  const onSubmitHandler = (e) => {
    e.preventDefault();
    let title = e.target[0].value;
    let amount = e.target[1].value;
    let note = e.target[2].value;

    let newLogObject = {
      type: expenseType === "income" ? "income" : "expense",
      title: title,
      amount: parseInt(amount),
      note: note,
      id: Math.random(),
      date: Date.now(),
    };

    appData.addLogHandler(newLogObject);
    props.onFormSubmission();
  };
  return (
    <div className={`${classes[selectedThemeClass]} ${classes["add-log-form-container"]}`}>
      <div className={classes["toggle-expense-type-button-container"]}>
        <Button
          className={` ${classes["toggle-expense-type-button"]} ${
            expenseType == "income" ? classes["selected-button"] : ""
          }`}
          onClick={changeExpenseTypeToIncome}
          title="Add Income"
        ></Button>
        <Button
          className={` ${classes["toggle-expense-type-button"]} ${
            expenseType == "expense" ? classes["selected-button"] : ""
          }`}
          onClick={changeExpenseTypeToExpense}
          title="Add Expense"
        ></Button>
      </div>
      <form onSubmit={onSubmitHandler}>
        <Input type="text" id="title" value="Title" />
        <Input type="number" id="amount" value="Amount" />
        <Input type="text" id="Note" value="Note" />
        <button type="submit" className={classes["form-submit-button"]}>
          {expenseType === "income" ? "Add Income" : "Add Expense"}
        </button>
      </form>
    </div>
  );
};

export default AddLogForm;
