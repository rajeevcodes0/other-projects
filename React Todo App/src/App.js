import React, { useState } from "react";

import Container from "./Components/Container";
import InputControl from "./Components/InputControl";
import TodoList from "./Components/TodoList";
import Head from './Components/Head'

let initialData = [
  {
    id: Math.random(),
    task: "Study React",
  },
  {
    id: Math.random(),
    task: "Make a todo in React",
  },
  {
    id: Math.random(),
    task: "Do some pushups",
  },
];

function App() {
  const [tasks, setTasks] = useState(initialData);
  const [inputText,setInputText]= useState("");

  const addTaskHandler = (event) => {
    event.preventDefault(); //do not refresh the page
    if(inputText.trim()==0){
      return;
    }
    let newTask = {
      id: Math.random(),
      task: inputText
    }
    setTasks((prevState)=>{
      
      return [...prevState,newTask];
    })
    setInputText("");
  };

  const inputChangeHandler = (event) => {
    setInputText(event.target.value);
  };

  const cancelItemHandler = (event) => {
    
    setTasks((prevState)=>{
      return prevState.filter((taskObject)=>{
        return taskObject.id != event.target.parentNode.dataset.id;
      })
    })
  }


  return (
    <div className="app">
      <Container>
        <Head/>
        <InputControl
          onAddTask={addTaskHandler}
          onInputChange={inputChangeHandler}
          inputValue = {inputText}
        />
        <TodoList cancelItemHandler={cancelItemHandler} data={tasks} />
      </Container>
    </div>
  );
}

export default App;
