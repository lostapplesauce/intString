import React from 'react'
import '../stylesheets/Header.css'

export default function Header() {
    return (
      <header className='container'>
        <h1>Troy Turner</h1>
        <div>
            <h3>mobile: 077 470 71417</h3>
            <h3 className='email'>email: troyturner444@gmail.com</h3>
        </div>
      </header>
    );
}