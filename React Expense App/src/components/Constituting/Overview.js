//importing libraries
import React from "react";

//importing stylesheets
import classes from './Overview.module.css';

//importing hooks
import { useContext } from "react";

//importing context

import AppData from "../../store/app-data";

//import UI components
import Card from "../UI/Card";
import Panel from "../UI/Panel";



const Overview = (props) => {
  console.log("rendering overview component");
  const appData = useContext(AppData);

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
      <div className={classes["overview-container"]}>
        <Panel heading="Income" text={`${appData.currencySymbol} ${appData.expenseData.income}`} className={`${classes[selectedThemeClass]} ${classes["income-panel"]}`}></Panel>
        <Panel heading="Expenses" text={`${appData.currencySymbol}  ${appData.expenseData.expense}`} className={`${classes[selectedThemeClass]} ${classes["expense-panel"]}`}></Panel>
      </div>
    </Card>
  );
};

export default Overview;
