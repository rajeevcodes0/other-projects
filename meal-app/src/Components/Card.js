import React from 'react';

import '../Stylesheets/Card.css';

const Card = (props) => {
    return(
        <div className="card">
            <h2>{props.name}</h2>
            <p>{props.description}</p>
            <img src={props.imageSource}/>
        </div>
    )
}

export default Card;