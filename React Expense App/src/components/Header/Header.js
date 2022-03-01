//importing libraries
import React from "react";

//importing stylesheets
import classes from "./Header.module.css";

//importing hooks
import { useContext } from "react";

//importing UI components
import Button from "../UI/Button";

//importing context
import AppData from "../../store/app-data";


const Header = (props) => {

  const appData = useContext(AppData)

  let selectedThemeClass ="";
  if(appData.selectedTheme==="dark"){
    selectedThemeClass="dark-mode-theme";
  }else if(appData.selectedTheme==="light"){
    selectedThemeClass="light-mode-theme"
  }else if(appData.selectedTheme==="violet"){
    selectedThemeClass="violet-mode-theme"
  }
  return (
    <div className={classes.header}>
      <h1>MoneyMatters</h1>
      <div className={classes["button-container"]}>
        <Button
          title={<i className={`${"fas fa-cog"} ${classes[selectedThemeClass] }`}></i>}
          className={`${classes.button}`}
          onClick={props.onSettingsButtonClick}
        ></Button>
      </div>
    </div>
  );
};

export default Header;
