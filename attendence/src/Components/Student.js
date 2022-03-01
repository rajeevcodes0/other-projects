import React from "react";

import "./Student.css";

const Student = (props) => {
  console.log("im a student");
  return (
    <li className="student">
      <p>{props.data.name}</p>
      <input
        type="radio"
        name={`attendanceInput-${props.data.id.toString()}`}
        value="present"
        onChange = {props.onSelectAttendance}
      />
      <input
        type="radio"
        name={`attendanceInput-${props.data.id.toString()}`}
        value="absent"
        onChange = {props.onSelectAttendance}
      />
    </li>
  );
};

export default Student;
