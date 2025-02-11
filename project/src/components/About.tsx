import React from 'react';
import { Code, Palette, Server, Users } from 'lucide-react';

const About = () => {
  const skills = [
    {
      icon: Code,
      title: 'Frontend Development',
      description: 'React, TypeScript, Tailwind CSS',
    },
    {
      icon: Server,
      title: 'Backend Development',
      description: 'Node.js, Express, PostgreSQL',
    },
    {
      icon: Palette,
      title: 'UI/UX Design',
      description: 'Figma, Adobe XD, Prototyping',
    },
    {
      icon: Users,
      title: 'Team Collaboration',
      description: 'Agile, Scrum, Git',
    },
  ];

  return (
    <div className="py-16 px-4 sm:px-6 lg:px-8 max-w-7xl mx-auto">
      <div className="text-center mb-16">
        <h2 className="text-3xl font-bold mb-4 bg-clip-text text-transparent bg-gradient-to-r from-primary-600 to-secondary-600">About Me</h2>
        <p className="text-lg text-gray-600 max-w-3xl mx-auto">
          With over 5 years of experience in web development, I specialize in creating
          responsive and user-friendly applications. My passion lies in solving complex
          problems and turning ideas into reality through elegant interfaces.
        </p>
      </div>

      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-8">
        {skills.map((skill, index) => (
          <div
            key={index}
            className="p-6 bg-white/60 backdrop-blur-sm rounded-xl shadow-lg hover:shadow-xl transition-all duration-300 transform hover:-translate-y-1 border border-primary-100/30"
          >
            <div className="bg-gradient-to-br from-primary-500 to-secondary-500 w-12 h-12 rounded-lg flex items-center justify-center mb-4">
              <skill.icon className="w-6 h-6 text-white" />
            </div>
            <h3 className="text-xl font-semibold text-primary-900 mb-2">{skill.title}</h3>
            <p className="text-gray-600">{skill.description}</p>
          </div>
        ))}
      </div>
    </div>
  );
};

export default About;