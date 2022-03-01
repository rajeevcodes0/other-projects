//importing libraries
import React from "react";

//importing hooks
import { useContext } from "react";

//importing context
import AppData from "../../store/app-data";

//importing stylesheets
import classes from "./SelectTheme.module.css";

const SelectTheme = () => {
   const appData =  useContext(AppData);

   const changeThemeHandler = (e)=>{
     appData.changeThemeHandler(e.target.dataset.theme);
   }
  return (
    <div className={classes["select-theme-container"]}>
      <p>Select Your Theme:</p>
      <div className={classes["theme-list-container"]}>
        <div className={`${appData.selectedTheme==="dark"?classes["selected-theme"]:""} ${classes["theme"]}`}>
          <label htmlFor="dark-theme">Dark</label>
          <button data-theme="dark" id="dark-theme" onClick={changeThemeHandler}></button>
        </div>
        <div className={`${appData.selectedTheme==="light"?classes["selected-theme"]:""} ${classes["theme"]}`}>
          <label htmlFor="light-theme">Light</label>
          <button data-theme="light" id="light-theme" onClick={changeThemeHandler}></button>
        </div>
        <div className={`${appData.selectedTheme==="violet"?classes["selected-theme"]:""} ${classes["theme"]}`}>
          <label htmlFor="violet-theme">Violet</label>
          <button data-theme="violet" id="violet-theme" onClick={changeThemeHandler}></button>
        </div>
      </div>
    </div>
  );
};

export default SelectTheme;
