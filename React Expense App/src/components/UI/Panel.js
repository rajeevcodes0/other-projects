//importing libraries
import React from 'react';

const Panel = (props)=>{
    return(
        <div className={props.className}>
            <h3>{props.heading}</h3>
            <p>{props.text}</p>
        </div>
    );
}

export default Panel;