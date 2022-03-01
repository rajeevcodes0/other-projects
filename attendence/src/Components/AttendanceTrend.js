import React from 'react';

import './AttendanceTrend.css';

import TrendList from './TrendList';

const AttendanceTrend = (props) => {
    return(
        <div className="attendance-trend">
            <TrendList data={props.data}/>
        </div>
    );
}

export default AttendanceTrend;