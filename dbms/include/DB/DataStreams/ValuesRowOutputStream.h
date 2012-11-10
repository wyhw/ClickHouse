#pragma once

#include <Poco/SharedPtr.h>

#include <DB/Core/Block.h>
#include <DB/IO/WriteBuffer.h>
#include <DB/DataStreams/IRowOutputStream.h>


namespace DB
{

using Poco::SharedPtr;


/** Поток для вывода данных в формате VALUES (как в INSERT запросе).
  */
class ValuesRowOutputStream : public IRowOutputStream
{
public:
	ValuesRowOutputStream(WriteBuffer & ostr_, const Block & sample_);

	void writeField(const Field & field);
	void writeFieldDelimiter();
	void writeRowStartDelimiter();
	void writeRowEndDelimiter();
	void writeRowBetweenDelimiter();

	RowOutputStreamPtr clone() { return new ValuesRowOutputStream(ostr, sample); }

private:
	WriteBuffer & ostr;
	const Block sample;
	DataTypes data_types;
	size_t field_number;
};

}

