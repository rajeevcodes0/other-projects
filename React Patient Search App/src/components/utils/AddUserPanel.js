import React from "react";
import Button from "../ui/Button";
import Input from "../ui/Input";

import DatePicker from "react-datepicker";
import "react-datepicker/dist/react-datepicker.css";

import AppManager from "../../store/app-manager";

import { useContext, useReducer } from "react";

import classes from "./AddUserPanel.module.css";
import ErrorDialog from "./ErrorDialog";

function formReducer(currentState, action) {
  //console.log(currentState);

  let newState = {};

  if (action.type === "form_submitted") {
    return {
      name: "",
      isNameValid: false,

      age: "",
      isAgeValid: false,

      address: "",
      isAddressValid: false,

      gender: "",
      isGenderValid: false,

      lastVisit: "",
      isLastVisitValid: false,

      isFormValid: false,
    };
  }

  if (action.type === "name_change") {
    newState = {
      ...currentState,
      name: action.value,
      isNameValid: Boolean(action.value.trim()),
    };
  }

  if (action.type === "age_change") {
    newState = {
      ...currentState,
      age: action.value,
      isAgeValid: action.value > 0 ? true : false,
    };
  }

  if (action.type === "address_change") {
    newState = {
      ...currentState,
      address: action.value,
      isAddressValid: action.value.trim().length > 0,
    };
  }

  if (action.type === "gender_change") {
    newState = {
      ...currentState,
      gender: action.value,
      isGenderValid:
        action.value === "male" ||
        action.value === "Male" ||
        action.value === "female" ||
        action.value === "Female"
          ? true
          : false,
    };
  }

  if (action.type === "last_visit_change") {
    newState = {
      ...currentState,
      lastVisit: action.value,
      isLastVisitValid: action.value ? true : false,
    };
  }

  let isFormValid = false;
  if (
    newState.isNameValid &&
    newState.isAgeValid &&
    newState.isAddressValid &&
    newState.isGenderValid &&
    newState.isLastVisitValid
  ) {
    isFormValid = true;
  } else {
    isFormValid = false;
  }
  newState.isFormValid = isFormValid;
  //console.log("the new state we are returning", newState);
  return newState;
}

const AddUserPanel = () => {
  const AppManagerContext = useContext(AppManager);

  const [formState, formDispatch] = useReducer(formReducer, {
    name: "",
    isNameValid: false,

    age: "",
    isAgeValid: false,

    address: "",
    isAddressValid: false,

    gender: "",
    isGenderValid: false,

    lastVisit: "",
    isLastVisitValid: false,

    isFormValid: false,
  });

  const nameOnChangeHandler = (e) => {
    formDispatch({ type: "name_change", value: e.target.value });
  };

  const ageOnChangeHandler = (e) => {
    formDispatch({ type: "age_change", value: parseInt(e.target.value) });
  };

  const addressOnChangeHandler = (e) => {
    formDispatch({ type: "address_change", value: e.target.value });
  };

  const genderOnChangeHandler = (e) => {
    formDispatch({ type: "gender_change", value: e.target.value });
  };

  const lastVisitOnChangeHandler = (date) => {
    // console.log(date.getDate());
    // console.log(date.getMonth());
    // console.log(date.getFullYear());
    formDispatch({ type: "last_visit_change", value: date });
  };

  const onSubmitHandler = (e) => {
    e.preventDefault();
    // const name = e.target[0].value.trim();
    // const age = parseInt(e.target[1].value);
    // const address = e.target[2].value.trim();
    // const gender = e.target[3].value[0].toUpperCase();
    // const lastVisit = e.target[4].value;
    const name = formState.name.trim();
    const age = parseInt(formState.age);
    const address = formState.address.trim();
    const gender = formState.gender.toUpperCase();
    //we are converting the date to dd-mm-yyyy format to be stored to the database
    const lastVisit = `${formState.lastVisit.getFullYear()}-${formState.lastVisit.getMonth()+1}-${
      formState.lastVisit.getDate()
    }`;

    const newPatientData = {
      name: name,
      age: age,
      address: address,
      gender: gender,
      lastVisit: lastVisit,
    };

    formDispatch({ type: "form_submitted" });
    // console.log("before submitting",newPatientData);
    AppManagerContext.addPatientHandler(newPatientData);
  };
  return (
    <div className={classes["add-user-panel-container-center-div"]}>
      <div className={classes["add-user-panel-container"]}>
        {AppManagerContext.isShowingDialog && (
          <ErrorDialog
            message={`${AppManagerContext.newlyGeneratedID} is the new ID`}
            time={1000 * 60 * 60}
            type="success"
          />
        )}

        <form onSubmit={onSubmitHandler}>
          <Input
            id="name"
            name="Name"
            type="text"
            onChange={nameOnChangeHandler}
            value={formState.name}
            className={classes["input-container"]}
          ></Input>
          <Input
            id="age"
            name="Age"
            type="number"
            onChange={ageOnChangeHandler}
            value={formState.age}
            className={classes["input-container"]}
          ></Input>
          <Input
            id="address"
            name="Address"
            type="text"
            onChange={addressOnChangeHandler}
            value={formState.address}
            className={classes["input-container"]}
          ></Input>
          <Input
            id="gender"
            name="Gender"
            type="text"
            onChange={genderOnChangeHandler}
            value={formState.gender}
            className={classes["input-container"]}
          ></Input>
          <div className={classes["date-container"]}>
            <label>Last Visit</label>
            <DatePicker
              selected={formState.lastVisit}
              onChange={lastVisitOnChangeHandler}
              dateFormat="dd/MM/yyyy"
              wrapperClassName={`${classes["date-picker"]}`}
            />
          </div>
          {/* <Input
            id="last-visit"
            name="Last Visit"
            type="date"
            onChange={lastVisitOnChangeHandler}
            value={formState.lastVisit}
            className={classes["input-container"]}
          ></Input> */}
          <Button
            type="submit"
            disabled={!formState.isFormValid}
            name="Submit"
            className={`${classes["submit-user-button"]}
              ${
                formState.isFormValid ? classes["active"] : classes["inactive"]
              }`}
          ></Button>
        </form>
      </div>
    </div>
  );
};

export default AddUserPanel;
