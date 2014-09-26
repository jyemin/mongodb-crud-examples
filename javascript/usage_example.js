

// find

	col.find({
		criteria: { x: 1 },
		limit: 10
	});

	col.find({
		skip: 20,
		tailable: true,
		awaitData: true
	});


// aggregate

	col.aggregate({
		pipeline: [
			{ $match : { x: 1 } },
			{ $skip: 10 }
		],
		allowDiskUse : true
	});


// count

	col.count({
		criteria: { x: 1 },
		maxTimeMS: 2000
	});


// distinct

	col.distinct({
		fieldName: "y",
		criteria: { x: 1 }
	});


// delete

	col.deleteOne({
		criteria: { x: 1 }
	});

	col.deleteOne({ x: 1 });

	col.deleteMany({ x: 1 });


// insert

	col.insertOne({ 
		document: { x: 1 }
	});

	col.insertOne({ x: 1 });

	col.insertMany({
		documents: [
			{ x: 1 },
			{ x: 2 },
		],
                ordered : false	
	});


// replaceOne

	col.replaceOne({
		criteria: { x: 1 },
		replacement: { x: 2 },
		upsert: true
	});

	col.replaceOne({ x: 1 }, { x: 2 }, { upsert: true });


// update

	col.updateOne({
		criteria: { x: 1 },
		update: { $set: { x: 2 } },
		upsert: true
	});

	col.updateMany({ x: 1 }, { $set: { x: 2 } }, { upsert: true });


// bulkWrite

	col.bulkWrite({
		requests: [{ 
			insertOne: { 
				document: { x: 1 } } 
			}, { 
			updateMany: { 
				criteria: { x: 1 }, 
				update: { $set: { x: 2 } }
			}, {
			deleteOne: {
				criteria: { x: 1 }
			}
		],
		ordered: false
	});


// findOneAndDelete

	col.findOneAndDelete({
		criteria: { x: 1 },
		projection: { y: 1, _id: 0 },
	});


// findOneAndReplace

	col.findOneAndReplace({
		criteria: { x: 1 },
		replacement: { x: 2 },
		returnOriginal: false
	});


// findOneAndUpdate

	col.findOneAndUpdate({
		criteria: { x: 1 },
		update: { $set: { x: 2 } },
		returnOriginal: false
	});


// explain

	col.explain({
	        command : {
			count : {
				criteria: { x: 1 },
				maxTimeMS: 2000
			}
		}
	});

	col.explain({
		command : {
			updateOne: {
				criteria: { x: 1 },
				update: { $inc: { x: 2 } }
			}
		},
		verbosity: "allPlansExecution"
	});

