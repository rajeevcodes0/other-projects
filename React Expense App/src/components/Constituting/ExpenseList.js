//importing libraries
import React from "react";

//importing stylesheets
import classes from "./ExpenseList.module.css";

//import UI components
import Card from "../UI/Card";
import ExpenseItem from "./ExpenseItem";

const ExpenseList = (props) => {
  console.log("rendering ExpenseList component");
  console.log("inside expense list",props);
  return (
    <Card>
      <div className={classes["expense-list-container"]}>
        {props.expenses.map((expense) => {
          return (
            <ExpenseItem
              key={expense.id}
              id={expense.id}
              date={expense.date}
              title={expense.title}
              amount={expense.amount}
            ></ExpenseItem>
          );
        })}
      </div>
    </Card>
  );
};

export default ExpenseList;
