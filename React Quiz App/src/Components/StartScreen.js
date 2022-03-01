import React from 'react';

import './StartScreen.css';

const StartScreen = (props) => {
    return(
        <div className="start-screen">
            <h1>Enter Your Name</h1>
            <form onSubmit={props.onSubmit}>
                <input type="text"/>
                <button type="submit">Submit</button>
            </form>
        </div>
    );
}

export default StartScreen;