import React from "react";
import Button from "../ui/Button";
import AppManager from "../../store/app-manager";
import { useContext } from "react";


import classes from "./Header.module.css";

const Header = () => {
  const appManagerContext = useContext(AppManager);
  return (
    <div className={classes["header-container"]}>
      <h1>Hello Doctor</h1>
      {appManagerContext.isUserLoggedIn ? (
        <div className={classes['log-out-button-container']}>
          <Button
            type="button"
            disabled={false}
            name="LogOut"
            onClick={appManagerContext.logOutHandler}
          ></Button>
        </div>
      ) : (
        ""
      )}
    </div>
  );
};

export default Header;
