import React from 'react';
import { ArrowRight } from 'lucide-react';

const HomePage = () => {
  return (
    <div className="min-h-[calc(100vh-4rem)] flex items-center justify-center">
      <div className="max-w-4xl mx-auto px-4 sm:px-6 lg:px-8 text-center">
        <div className="relative mb-8">
          <div className="absolute inset-0 bg-gradient-to-br from-primary-200 to-secondary-200 rounded-full blur-3xl opacity-20"></div>
          <img
            src="https://images.unsplash.com/photo-1535713875002-d1d0cf377fde?auto=format&fit=crop&q=80&w=200&h=200"
            alt="Profile"
            className="relative w-32 h-32 rounded-full mx-auto object-cover shadow-xl ring-4 ring-white"
          />
        </div>
        <h1 className="text-5xl font-bold text-gray-900 mb-4 bg-clip-text text-transparent bg-gradient-to-r from-primary-600 to-secondary-600">John Doe</h1>
        <p className="text-xl text-primary-700 mb-8 font-medium">Full Stack Developer & UI/UX Designer</p>
        <p className="text-lg text-gray-600 mb-12 max-w-2xl mx-auto">
          Crafting digital experiences with a passion for clean code and beautiful design.
          Specialized in React, Node.js, and modern web technologies.
        </p>
        <a
          href="#contact"
          className="inline-flex items-center px-6 py-3 text-base font-medium rounded-full text-white bg-gradient-to-r from-primary-600 to-secondary-600 hover:from-primary-700 hover:to-secondary-700 transform hover:scale-105 transition-all duration-200 shadow-lg hover:shadow-xl"
        >
          Let's Connect
          <ArrowRight className="ml-2 w-5 h-5" />
        </a>
      </div>
    </div>
  );
}

export default HomePage;