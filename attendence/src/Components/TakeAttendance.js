import React from 'react';

import './TakeAttendance.css';

import PA from './PA';
import StudentList from './StudentList';
const TakeAttendance = (props) => {
    return(
        <div className="take-attendance">
            <PA/>
            <StudentList data={props.data} onSelectAttendance={props.onSelectAttendance}/>
        </div>
    );
}

export default TakeAttendance;