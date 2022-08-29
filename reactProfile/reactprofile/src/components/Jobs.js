import React from 'react'
import '../stylesheets/Jobs.css'

// Portion to talk about Job expierence extracted from data file

export default function Jobs(props) {
    return(
    <div className="job--container">
        <p className="job--title">{props.job}</p>
        <p className="job--date">{props.date }</p>    
        <p className="job--description">{props.description}</p>
    </div>
    )
}