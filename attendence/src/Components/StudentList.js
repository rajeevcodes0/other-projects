import React from "react";

import Student from "./Student";
import "./StudentList.css";
const StudentList = (props) => {
  console.log("im a student list");
  console.log(props);
  return (
    <ul className="student-list">
      {props.data.map((dataElement) => {
        return (
          <Student
            id={dataElement.id}
            data={dataElement}
            onSelectAttendance={props.onSelectAttendance}
          />
        );
      })}
    </ul>
  );
};

export default StudentList;
