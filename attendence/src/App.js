import React, { useState } from "react";

import Navigation from "./Components/Navigation";
import TakeAttendance from "./Components/TakeAttendance";
import AttendanceTrend from "./Components/AttendanceTrend";

const INITIAL_DATA = [
  {
    id: Math.random(),
    name: "Rajeev",
    attendance: [true, false, false, true, false, false, false],
  },
  {
    id: Math.random(),
    name: "Sachin",
    attendance: [true, true, true, true, true, true, false],
  },
  {
    id: Math.random(),
    name: "Ayush",
    attendance: [true, true, true, true, true, true, true],
  },
  {
    id: Math.random(),
    name: "Ram",
    attendance: [true, false, false, true, false, false, false],
  },
  {
    id: Math.random(),
    name: "Shekhar",
    attendance: [true, false, false, true, false, true, false],
  },
  {
    id: Math.random(),
    name: "Nitin",
    attendance: [true, false, true, true, false, true, false],
  },
  {
    id: Math.random(),
    name: "Vaibhav Rawat",
    attendance: [false, false, false, false, false, false, false],
  },
];

const App = () => {
  const [appState, setAppState] = useState(INITIAL_DATA);
  const [selectedComponent, setSelectedComponent] = useState("takeAttendance");

  const selectComponentHandler = (event) => {
    console.log("save afg")
    if (event.target.innerText == "Take Attendance") {
      setSelectedComponent("takeAttendance");
    } else {
      setSelectedComponent("trend");
    }
  }

  const selectAttendanceHandler = (event) => {
    let targetStudentID = parseFloat(event.target.name.split("-")[1]);
    let targetValue = event.target.value=="present"?true:false;
    console.log(targetValue);
    setAppState((prevState)=>{
      for(let i=0;i<prevState.length;i++){
        if(prevState[i].id==targetStudentID){
          prevState[i].attendance.push(targetValue);
        }
      }
      return prevState;
    })

  }
  return (
    <div>
      <Navigation onSelectComponent={selectComponentHandler} />
      {selectedComponent == "takeAttendance" ? (
        <TakeAttendance  onSelectAttendance={selectAttendanceHandler} data={appState} />
      ) : (
        <AttendanceTrend  data={appState} />
      )}
    </div>
  );
};

export default App;
