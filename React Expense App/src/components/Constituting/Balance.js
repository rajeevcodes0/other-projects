//importing libraries
import React from "react";

//importing hooks
import { useContext } from "react";

//importing context

import AppData from "../../store/app-data";

//import stylesheets
import classes from "./Balance.module.css";

//import UI components
import Card from "../UI/Card";
import Panel from "../UI/Panel";
import Button from "../UI/Button";

const Balance = (props) => {
  console.log("rendering Balance component");
  const appData = useContext(AppData);
  console.log("income", appData.expenseData.income);
  console.log("expense", appData.expenseData.expense);


  let selectedThemeClass ="";
  if(appData.selectedTheme==="dark"){
    selectedThemeClass="dark-mode-theme";
  }else if(appData.selectedTheme==="light"){
    selectedThemeClass="light-mode-theme"
  }else if(appData.selectedTheme==="violet"){
    selectedThemeClass="violet-mode-theme"
  }

  return (
    <Card>
      <div className={`${classes[selectedThemeClass]} ${classes["balance-container"]}`}>
        <div className={classes["balance-info"]}>
          <Panel heading="Balance" text={`${appData.currencySymbol} ${appData.expenseData.income - appData.expenseData.expense}`}></Panel>
        </div>
        <div className={classes["add-balance"]}>
          <Button title={<i class="fas fa-plus-circle"></i>} className={classes.button} onClick={props.onToggleAddLogForm}></Button>
        </div>
      </div>
    </Card>
  );
};

export default Balance;
