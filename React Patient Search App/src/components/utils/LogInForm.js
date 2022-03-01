import React from "react";

import { useContext } from "react";
import AppManager from "../../store/app-manager";
import Button from "../ui/Button";
import Input from "../ui/Input";
import ErrorDialog from "./ErrorDialog";

import classes from "./LogInForm.module.css";

const LogInForm = () => {
  const appManagerContext = useContext(AppManager);

  const onSubmitHandler = (e) => {
    e.preventDefault();
    const username = e.target[0].value;
    const password = e.target[1].value;
    // console.log(username, password);

    const authData = {
      username: username,
      password: password,
    };
    appManagerContext.logInHandler(authData);
  };
  return (
    <React.Fragment>
      {appManagerContext.isShowingDialog && (
        <ErrorDialog
          message="Check Your Username or Password"
          time={5000}
          type="error"
        />
      )}
      <div className={classes["log-in-form-container"]}>
        <h2>Sign In</h2>
        <form onSubmit={onSubmitHandler}>
          <Input
            id="username"
            name="Username"
            type="text"
            className={classes["input-container"]}
          ></Input>

          <Input
            id="password"
            name="Password"
            type="password"
            className={classes["input-container"]}
          ></Input>
          <Button name="Sign In" type="submit" disabled={false}></Button>
        </form>
      </div>
    </React.Fragment>
  );
};

export default LogInForm;
