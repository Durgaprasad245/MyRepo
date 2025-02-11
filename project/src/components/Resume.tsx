import React from 'react';
import { Calendar, Building2, GraduationCap, Download } from 'lucide-react';

const Resume = () => {
  const experience = [
    {
      title: 'Senior Frontend Developer',
      company: 'Tech Corp',
      period: '2021 - Present',
      description: 'Led development of multiple React applications, improving performance by 40%',
    },
    {
      title: 'Full Stack Developer',
      company: 'Digital Solutions Inc',
      period: '2019 - 2021',
      description: 'Developed and maintained various web applications using React and Node.js',
    },
  ];

  const education = [
    {
      degree: 'Master of Computer Science',
      school: 'Tech University',
      period: '2017 - 2019',
    },
    {
      degree: 'Bachelor of Computer Science',
      school: 'State University',
      period: '2013 - 2017',
    },
  ];

  return (
    <div className="py-16 px-4 sm:px-6 lg:px-8 max-w-4xl mx-auto">
      <div className="bg-white/60 backdrop-blur-sm rounded-2xl shadow-lg p-8 border border-primary-100/30">
        <div className="flex justify-between items-center mb-12">
          <h2 className="text-3xl font-bold bg-clip-text text-transparent bg-gradient-to-r from-primary-600 to-secondary-600">Resume</h2>
          <button className="inline-flex items-center px-4 py-2 rounded-full text-white bg-gradient-to-r from-primary-600 to-secondary-600 hover:from-primary-700 hover:to-secondary-700 transform hover:scale-105 transition-all duration-200 shadow-md hover:shadow-lg">
            <Download className="w-5 h-5 mr-2" />
            Download CV
          </button>
        </div>

        <div className="mb-12">
          <h3 className="text-xl font-semibold text-primary-900 mb-6 flex items-center">
            <Building2 className="w-5 h-5 mr-2 text-primary-600" />
            Work Experience
          </h3>
          <div className="space-y-8">
            {experience.map((job, index) => (
              <div key={index} className="border-l-2 border-gradient-to-b from-primary-200 to-secondary-200 pl-4">
                <h4 className="text-lg font-semibold text-primary-900">{job.title}</h4>
                <p className="text-primary-600 font-medium">{job.company}</p>
                <p className="text-gray-500 flex items-center mt-1">
                  <Calendar className="w-4 h-4 mr-2" />
                  {job.period}
                </p>
                <p className="text-gray-600 mt-2">{job.description}</p>
              </div>
            ))}
          </div>
        </div>

        <div>
          <h3 className="text-xl font-semibold text-primary-900 mb-6 flex items-center">
            <GraduationCap className="w-5 h-5 mr-2 text-primary-600" />
            Education
          </h3>
          <div className="space-y-8">
            {education.map((edu, index) => (
              <div key={index} className="border-l-2 border-gradient-to-b from-primary-200 to-secondary-200 pl-4">
                <h4 className="text-lg font-semibold text-primary-900">{edu.degree}</h4>
                <p className="text-primary-600 font-medium">{edu.school}</p>
                <p className="text-gray-500 flex items-center mt-1">
                  <Calendar className="w-4 h-4 mr-2" />
                  {edu.period}
                </p>
              </div>
            ))}
          </div>
        </div>
      </div>
    </div>
  );
};

export default Resume;