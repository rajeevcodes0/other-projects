import React from 'react';

import '../Stylesheets/Buttons.css';

const Buttons = (props) => {
    return(
        <div className="buttons">
            <button onClick={props.onClick}>Breakfast</button>
            <button onClick={props.onClick}>Lunch</button>
            <button onClick={props.onClick}>Dinner</button>
            <button onClick={props.onClick}>All</button>
        </div>
    )
}

export default Buttons;