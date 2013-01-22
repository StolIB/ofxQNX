//
// LogFile.h
//
// $Id: //poco/1.4/Foundation/include/Poco/LogFile.h#2 $
//
// Library: Foundation
// Package: Logging
// Module:  LogFile
//
// Definition of the LogFile class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_LogFile_INCLUDED
#define Foundation_LogFile_INCLUDED


#include "Poco/Foundation.h"


#if defined(POCO_OS_FAMILY_WINDOWS) && defined(POCO_WIN32_UTF8)
#include "Poco/LogFile_WIN32U.h"
#elif defined(POCO_OS_FAMILY_WINDOWS)
#include "Poco/LogFile_WIN32.h"
#elif defined(POCO_OS_FAMILY_VMS)
#include "Poco/LogFile_VMS.h"
#else
#include "Poco/LogFile_STD.h"
#endif


namespace Poco {


class Foundation_API LogFile: public LogFileImpl
	/// This class is used by FileChannel to work
	/// with a log file.
{
public:
	LogFile(const std::string& path);
		/// Creates the LogFile.

	~LogFile();
		/// Destroys the LogFile.

	void write(const std::string& text, bool flush = true);
		/// Writes the given text to the log file.
		/// If flush is true, the text will be immediately
		/// flushed to the file.
	
	UInt64 size() const;
		/// Returns the current size in bytes of the log file.
	
	Timestamp creationDate() const;
		/// Returns the date and time the log file was created.
	
	const std::string& path() const;
		/// Returns the path given in the constructor.
};


//
// inlines
//
inline void LogFile::write(const std::string& text, bool flush)
{
	writeImpl(text, flush);
}


inline UInt64 LogFile::size() const
{
	return sizeImpl();
}


inline Timestamp LogFile::creationDate() const
{
	return creationDateImpl();
}


inline const std::string& LogFile::path() const
{
	return pathImpl();
}


} // namespace Poco


#endif // Foundation_LogFile_INCLUDED
