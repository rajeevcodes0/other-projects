//importing libraries
import React from "react";

//importing hooks
import { useReducer } from "react";
import { useState } from "react";
//the default context is of no use as long as we are using a Provider
//we are using the following values just for IDE support

const AppData = React.createContext({
  income: 0,
  expense: 0,
  logArray: [],
  addLogHandler: () => {},
  deleteLog: () => {},
  editLog: () => {},
  selectedTheme: "",
  changeThemeHandler: ()=>{}
});

const newExpenseIncomeValues=(newLogArray)=>{


  let expense=0,income=0;

  for(let i=0;i<newLogArray.length;i++){
    if(newLogArray[i].type=="income"){
      income+=newLogArray[i].amount;
    }else{
      expense+=newLogArray[i].amount;
    }
  }

  console.log("returning new income and expenses hehe",income,expense);
  return [income,expense];
}


//initial function for our useReducer hook
const initialExpenseReducer = (initialState)=>{

  const [newExpense,newIncome] = newExpenseIncomeValues(initialState.logArray);
  return {
    income: newIncome,
    expense: newExpense,
    logArray: initialState.logArray,
  };
}

const expenseReducer = (currentState, action) => {
  if (action.type === "deleteLog") {
    const newLogArray = currentState.logArray.filter((log) => {
      return !(action.itemID == log.id);
    });

    const [newIncome,newExpense] = newExpenseIncomeValues(newLogArray);
    return {
      income: newIncome,
      expense: newExpense,
      logArray: newLogArray,
    };
  }

  if (action.type === "addLog") {
    //pushing the new log into the array
    console.log("adding a new log");
    console.log(action.newLogObject);
    currentState.logArray.push(action.newLogObject);
    const [newIncome,newExpense] = newExpenseIncomeValues(currentState.logArray);

    console.log("object being returned after add",{
      income: newIncome,
      expense: newExpense,
      logArray: currentState.logArray,
    })
    return {
      income: newIncome,
      expense: newExpense,
      logArray: currentState.logArray,
    };
  }

  //default returns, will be used to copy(to not have bugs) and return default
  return {
    income: 0,
    expense: 0,
    logArray: [],
  };
};

export const AppDataProvider = (props) => {
  console.log("rendering appdataprovider now");
  const [expenseState, expenseDispatch] = useReducer(expenseReducer, {
    income: 0,
    expense: 0,
    logArray: [
      {
        id: Math.random(),
        type: "expense",
        title: "expense 1",
        amount: 200,
        note: "yuss",
        date: Date.now(),
      },
      {
        id: Math.random(),
        type: "income",
        title: "income 1",
        amount: 200,
        note: "yuss",
        date: Date.now(),
      },
      {
        id: Math.random(),
        type: "expense",
        title: "expense 2",
        amount: 200,
        note: "yuss",
        date: Date.now(),
      }
    ],
  },initialExpenseReducer);

  const [currencySymbol, setCurrencySymbol] = useState("$");
  const [selectedTheme, setSelectedTheme] = useState("light");

  const deleteLogHandler = (id) => {
    expenseDispatch({ type: "deleteLog", itemID: id });
  };

  const addLogHandler = (newLogObject) => {
    expenseDispatch({ type: "addLog", newLogObject: newLogObject });
  };

  const changeThemeHandler = (newTheme)=>{
    setSelectedTheme(newTheme);
  }

  console.log("before returning contextprovider");
  return (
    <AppData.Provider
      value={{
        expenseData: expenseState,
        deleteLogHandler: deleteLogHandler,
        addLogHandler: addLogHandler,
        currencySymbol: currencySymbol,
        selectedTheme:selectedTheme,
        changeThemeHandler:changeThemeHandler
      }}
    >
      {props.children}
    </AppData.Provider>
  );
};

export default AppData;
